#include "commom.hpp"
#include <Accelerate/Accelerate.h>
#include <arm_neon.h>
#include <chrono>
#include <gtest/gtest.h>

/**
 * @brief
 * hw.perflevel1.l1icachesize: 131072
 * hw.perflevel1.l1dcachesize: 65536
 * hw.perflevel1.l2cachesize: 4194304
 * hw.perflevel0.l1icachesize: 196608
 * hw.perflevel0.l1dcachesize: 131072
 * hw.perflevel0.l2cachesize: 16777216
 * hw.cacheconfig: 12 1 4 0 0 0 0 0 0 0
 * hw.cachesize: 3434299392 65536 4194304 0 0 0 0 0 0 0
 * hw.cachelinesize: 128
 * hw.l1icachesize: 131072
 * hw.l1dcachesize: 65536
 * hw.l2cachesize: 4194304
 * security.mac.amfi.trust
 */

void benchmark(const std::vector<size_t> &dims,
               std::function<void(void)> func) {
  const int warmup_times = 5;
  const int infer_times = 20;

  // warmup
  for (int i = 0; i < warmup_times; ++i)
    func();

  auto start_time = std::chrono::steady_clock::now();
  // run
  for (int i = 0; i < infer_times; ++i)
    func();

  // latency
  auto end_time = std::chrono::steady_clock::now();

  // compute GFLOPs
  double sec = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time -
                                                                    start_time)
                   .count() *
               1e-9;
  auto flops = (2.0f * dims[0] * dims[1] * dims[2] * infer_times) / sec;

  // print
  std::cout << std::setw(20) << " GFLOPs: " << flops * 1.0e-09 << std::endl;
}

const size_t M = 384, N = 1024, K = 8196;
float A[M * K];
float B[K * N];
float C[M * N];
float RefC[M * N];

void init_mat() {
  for (size_t i = 0; i < M * K; i++) {
    A[i] = (float)i / (M * K);
  }
  for (size_t i = 0; i < K * N; i++) {
    B[i] = (float)i / (K * N);
  }
  for (size_t i = 0; i < M * N; i++) {
    C[i] = RefC[i] = 0;
  }

  cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, 1.0f, A, K, B,
              N, 0.0f, RefC, N);
}

void check_mat() {
  for (size_t i = 0; i < M * N; i++) {
    assert(C[i] == RefC[i]);
  }
}

/**
 * @brief GFLOPs: 0.571637
 *
 */
// void native() {
//   for (size_t m = 0; m < M; m++) {
//     for (size_t n = 0; n < N; n++) {
//       C[m * N + n] = 0.0f;
//       for (size_t k = 0; k < K; k++) {
//         C[m * N + n] += A[m * K + k] * B[k * N + n];
//       }
//     }
//   }
// }

// TEST(test_gemm, native) {
//   init_mat();
//   benchmark({M, K, N}, native);
//   check_mat();
// }

// 1162.57 gflops
TEST(test_gemm, cblas) {
  init_mat();
  auto refer = [&]() {
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, 1.0f, A, K,
                B, N, 0.0f, C, N);
  };
  benchmark({M, K, N}, refer);
  check_mat();
}

/**
 * @brief cacheline为128, 那么按顺序访问K时,
 * 下一次要加载的数据肯定不在cache中,所以改变循环顺序
 * GFLOPs: 1.34475
 */
void opt_v1() {
  for (size_t m = 0; m < M; m++) {
    for (size_t k = 0; k < K; k++) {
      for (size_t n = 0; n < N; n++) {
        if (k == 0) {
          C[m * N + n] = 0.0f;
        }
        C[m * N + n] += A[m * K + k] * B[k * N + n];
      }
    }
  }
}

// TEST(test_gemm, opt_v1) {
//   init_mat();
//   benchmark({M, K, N}, opt_v1);
//   check_mat();
// }

/**
 * @brief  l1 dcache 为65536. K=1024, 如果都cache B矩阵可以存16行
 * 观察上面的循环, 我们知道每个不同的m都要去访问相同的n
 * 但是B矩阵的只能cache 16行, 也就是改变不同的m时又需要重新load,
 * 所以可以通过tile K来限制cache B的行数.
 * GFLOPs: 1.34475
 */
void opt_v2() {
  const size_t TileK = 32;
  for (size_t ok = 0; ok < K; ok += TileK) {
    for (size_t m = 0; m < M; m++) {
      auto IK = std::min(K, ok + TileK);
      for (size_t ik = ok; ik < IK; ik++) {
        for (size_t n = 0; n < N; n++) {
          if (ik == 0) {
            C[m * N + n] = 0.0f;
          }
          C[m * N + n] += A[m * K + ik] * B[ik * N + n];
        }
      }
    }
  }
}

// TEST(test_gemm, opt_v2) {
//   init_mat();
//   benchmark({M, K, N}, opt_v2);
//   check_mat();
// }

/**
 * @brief  l1 dcache 为65536. K=1024, 如果都cache B矩阵可以存16行
 * 根据z3 solver出来的tile size发现并没有效果.
 * 这里动ok的话, AB矩阵都会有stride, 所以把oK放在最外层.
 * 这样两个矩阵至少能cache住一个. GFLOPs: 1.35811
 */
void opt_v3() {
  const size_t TileK = 4;
  const size_t TileM = 4;
  const size_t TileN = 4092;
  for (size_t ok = 0; ok < K; ok += TileK) {
    for (size_t om = 0; om < M; om += TileM) {
      for (size_t on = 0; on < N; on += TileN) {
        auto IM = std::min(M, om + TileM);
        for (size_t im = om; im < IM; im++) {
          auto IK = std::min(K, ok + TileK);
          for (size_t ik = ok; ik < IK; ik++) {
            auto IN = std::min(N, on + TileN);
            for (size_t in = on; in < IN; in++) {
              if (ik == 0) {
                C[im * N + in] = 0.0f;
              }
              C[im * N + in] += A[im * K + ik] * B[ik * N + in];
            }
          }
        }
      }
    }
  }
}

// TEST(test_gemm, opt_v3) {
//   init_mat();
//   benchmark({M, K, N}, opt_v3);
//   check_mat();
// }

/**
 * @brief 现在我们的cache效率都足够了, 开始提升计算效率
 *
 */
void opt_v4() {
  asm("fmla v0.4s, v16.4s, v17.s[0]");
  asm("fmla v1.4s, v16.4s, v17.s[1]");
  asm("fmla v2.4s, v16.4s, v17.s[2]");
  asm("fmla v3.4s, v16.4s, v17.s[3]");
  asm("fmla v4.4s, v16.4s, v17.s[0]");
  asm("fmla v5.4s, v16.4s, v17.s[1]");
  asm("fmla v6.4s, v16.4s, v17.s[2]");
  asm("fmla v7.4s, v16.4s, v17.s[3]");
  asm("subs x0, x0, #1");
  asm("fmla v8.4s, v16.4s, v17.s[0]");
  asm("fmla v9.4s, v16.4s, v17.s[1]");
  asm("fmla v10.4s, v16.4s, v17.s[2]");
  asm("fmla v11.4s, v16.4s, v17.s[3]");
  asm("fmla v12.4s, v16.4s, v17.s[0]");
  asm("fmla v13.4s, v16.4s, v17.s[1]");
  asm("fmla v14.4s, v16.4s, v17.s[2]");
  asm("fmla v15.4s, v16.4s, v17.s[3]");
}

// TEST(test_gemm, opt_marco_kernel) {
//   init_mat();

//   benchmark({M, K, N}, opt_v4);
//   auto v0 = vdupq_n_f32(2);
//   float32x4_t v1;
//   v1 = vfmaq_f32(v1, v0, v0);
//   printf("%f\n", vgetq_lane_f32(v1, 0));
//   printf("%f\n", vgetq_lane_f32(v1, 1));
//   printf("%f\n", vgetq_lane_f32(v1, 2));
//   printf("%f\n", vgetq_lane_f32(v1, 3));
//   // check_mat();
// }