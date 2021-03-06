#include "commom.hpp"
// 构造函数就不能是虚函数.
// class 重写构造函数 {
//  public:
//   int x;
//   virtual 重写构造函数(int _i) { x = _i - 1; }
// };
// class 重写构造函数2 : public 重写构造函数 {
// public:
//   virtual 重写构造函数(int _i) { x = _i + 1; }
//   重写构造函数2(int _i) { 重写构造函数(_i); }
// }



int main(int argc, char const* argv[]) {
  重写构造函数2(1);
  return 0;
}
