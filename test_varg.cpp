#include <gtest/gtest.h>

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

/**
 * @brief 获取不同长度的可变参数，打印参数的个数
 *
 * @tparam T
 * @param args
 */
template <typename... T>
void func(T... args)
{
  cout << sizeof...(args) << endl;
  cout << sizeof...(T) << endl;
}

TEST(test_varg, basic)
{
  func();
  func(1);
  func(1, 2);
  func(1, 2, '3', vector<int>{3});
}
/**
 [ RUN      ] test_varg.basic
  0
  1
  2
  4
  [       OK ] test_varg.basic (0 ms)
 */

void print() { cout << " ;" << endl; }
template <typename T>
void print(T v)
{
  cout << v << " ";
}
template <typename T, typename... Args>
void print(T head, Args... args)
{
  print(head);
  cout << "remain size : " << sizeof...(args) << endl;
  print(args...);
}

TEST(test_varg, recursive_print_error_version)
{
  print();
  print(1, 2);
  print(1, 2.3, '3');
}
/**
 [ RUN      ] test_varg.recursive_print
  ;
  1 remain size : 1
  2 1 remain size : 2
  2.3 remain size : 1
  3 [       OK ] test_varg.recursive_print (0 ms)
 */

void ic() { cout << " ; " << endl; }
template <typename T, typename... Args>
void ic(T head, Args... args)
{
  cout << head << " ";
  ic(args...);
}

template <typename T>
T sums()
{
  return (T)(-2);
}
template <typename T, typename... Ts>
T sums(T v, Ts... vs)
{
  return v + sums<T>(vs...);
}

TEST(test_varg, recursive_print_right_version)
{
  ic(sums(1, 2));
  ic(sums(1, 2.3, 3.5));
  ic(sums(2.3, 1, 3.5));
}
/*
[ RUN      ] test_varg.recursive_print_right_version
1  ;
4  ;
4.8  ;
[       OK ] test_varg.recursive_print_right_version (0 ms)
*/

template <typename T>
int toint(T t)
{
  return (int)t;
}

template <typename... Args>
vector<int> toints(Args... args)
{
  vector<int> arr = {toint(args)...};
  return arr;
}

template <typename... Args>
vector<int> countargs(Args... args)
{
  int cnt = 0;
  vector<int> arr = {(args, cnt++)...};
  return arr;
}

template <typename Head, typename... Args>
void print2(Head head, Args... args)
{
  cout << head;
  if constexpr (sizeof...(args) > 0)
  {
    cout << " , ";
    print2(args...);
  }
  else
  {
    cout << " ; " << endl;
  }
}

template <typename T, typename... Ts>
auto print3(T value, Ts... args)
{
  std::cout << value << std::endl;
  (void)std::initializer_list<T>{
      ([&args]
       { std::cout << args << std::endl; }(),
       value)...};
}

TEST(test_varg, expand_right_version)
{
  auto arr = toints(1.2, 2.4, 3.6, 4.7);
  for (size_t i = 0; i < arr.size(); i++)
  {
    ic(arr[i]);
  }
  auto arr2 = countargs(1.2, 2.4, 3.6, 4.7);
  for (size_t i = 0; i < arr2.size(); i++)
  {
    ic(arr2[i]);
  }
  print2("hello", "word", "yes", 1, 3, 4.5);
}

template <typename... T>
auto rsub(T... t)
{
  return (t - ...);
}
template <typename... T>
auto lsub(T... t)
{
  return (... - t);
}

TEST(test_varg, fold_expressions)
{
  cout << rsub(1, 2, 3, 4, 5) << endl;
  cout << lsub(1, 2, 3, 4, 5) << endl;
}
/*  可变模版参数类   */

template <typename... Types> // 声明
class Sums
{
};

template <typename First> // 终止
class Sums<First>
{
public:
  enum
  {
    v = sizeof(First)
  };
};

template <typename First, typename... Types> // 递归
class Sums<First, Types...>
{
public:
  enum
  {
    v = Sums<First>::v + Sums<Types...>::v
  };
};

TEST(test_varg, var_class)
{
  Sums<int, float, double> s;
  cout << s.v << endl;
}

class Mat
{
public:
  float *data;
  int w, h, c, elempack, total;
  size_t elemsize;
  Mat(int w, size_t elemsize = 4, int elempack = 1)
      : Mat(w, 1, 1, elemsize, elempack) {}
  Mat(int w, int h, size_t elemsize = 4, int elempack = 1)
      : Mat(w, h, 1, elemsize, elempack) {}
  Mat(int w, int h, int c, size_t elemsize = 4, int elempack = 1)
      : w(w),
        h(h),
        c(c),
        elemsize(elemsize),
        elempack(elempack),
        total(w * h * c)
  {
    data = new float[total];
  }
  ~Mat() { delete[] data; }
};

// template <typename... Args>
// Mat InitMat(Args... args, int v, size_t elemsize = 4, int elempack = 1) {
//   auto m = InitMat(args..., elemsize, elempack);
//   fill_n(m.data, m.total, v);
// }

// template <typename T>
// struct initlist_size {
//   value;
// };

TEST(test_varg, make_from_tuple)
{
  // array<int, 3> in_shape{1, 2, 3};
  // auto m = InitMat(1, 2, 4, 4);
  // auto m = apply(Mat, {1, 2, 3});
  auto m = make_from_tuple<Mat>(make_tuple(1, 2, 3));
  ic(m.w, m.w, m.h);
  // auto m2 = InitMat({1, 3});
}

// 尝试使用模板生成
#include "isa.h"

template <size_t N>
struct isaseq_t
{
  char value[N];
};

template <size_t N, size_t... I>
constexpr isaseq_t<N> convert_tobyte_impl(const std::array<char, N> &arr, std::index_sequence<I...> indexs)
{
  constexpr isaseq_t<N> seq;
  ((seq.value[I] = arr[I]), ...);
  return seq;
}

template <size_t Base, size_t M, size_t N, size_t... I>
void copy_impl(isaseq_t<M> &dest, const isaseq_t<N> &src, std::index_sequence<I...> indexs)
{
  ((dest.value[Base + I] = src.value[I]), ...);
}

template <size_t N, typename Indices = std::make_index_sequence<N>>
constexpr isaseq_t<N> convert_tobyte(const std::array<char, N> &isaseq_t)
{
  return convert_tobyte_impl(isaseq_t, Indices{});
}

template <size_t N, size_t M,
          typename IndicesN = std::make_index_sequence<N>,
          typename IndicesM = std::make_index_sequence<M>>
constexpr isaseq_t<N + M> concat_seq(const isaseq_t<N> &a, const isaseq_t<M> &b)
{
  constexpr isaseq_t<N + M> seq;
  copy_impl<0>(seq, a, IndicesN{});
  copy_impl<N>(seq, b, IndicesM{});
  return seq;
}

template <char... Bytes>
using byte_sequence = std::integer_sequence<char, Bytes...>;

template <typename T>
struct identity
{
  using type = T;
};

template <typename Lhs, typename Rhs>
struct byte_sequence_concat
{
};

template <char... Lhs, char... Rhs>
struct byte_sequence_concat<byte_sequence<Lhs...>,
                            byte_sequence<Rhs...>>
    : byte_sequence<Lhs..., Rhs...>
{
};

// template <INST_MFU_MN_CONF Inst>
// struct make_byte_sequence_impl : std::make_index_sequence<sizeof(INST_MFU_MN_CONF)>
// {
// };

// using namespace nncase::runtime::k510::isa;
// #define inst_mn_conf_ ((const char *)(&inst_mn_conf));

// TEST(test_isa, static_isa)
// {
//   constexpr INST_MFU_MN_CONF inst_mn_conf{
//       OPCODE_MFU_MN_CONF,
//       MFU_MN_PORTOUT_SQR_IN_0,
//       MFU_MN_PORTOUT_DUMMY};

//   constexpr INST_MFU_MN_MAP_COMPUTE inst_mn_map_compute{};

//   ic(sizeof(inst_mn_conf), sizeof(inst_mn_map_compute));
//   constexpr byte_sequence<0x00, 0x01> b;
//   ic(sizeof(inst_mn_conf), sizeof(INST_MFU_MN_CONF));
//   ic(sizeof(b));
//   // ic(a.array::size);
//   // auto seqa = convert_tobyte(a.array);
//   // auto seqb = convert_tobyte(b.array);
//   // auto seqc = concat_seq(seqa, seqb);
// }