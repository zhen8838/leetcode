#include <iostream>
using namespace std;

/*
* 多重继承就是d间接继承了两次a,这样a中的变量会被继承两次,就分不清是哪个变量了.
    a
  /  \
  b  c
   \ /
    d
* 可以用域来指明是哪个子类的变量,不过类多了也一样 Base2::var1 = tmp;

* 或者在Base2.Base3继承的时候使用虚基类继承
* class Base2 : virtual public Base1

*/

// 间接基类
class Base1 {
 public:
  int var1;
};

// 直接基类
class Base2 : virtual public Base1 {
 public:
  int var2;
};

// 直接基类
class Base3 : virtual public Base1 {
 public:
  int var3;
};

// 派生类
class Derive : public Base2, public Base3 {
 public:
  void set_var1(int tmp) {
    var1 = tmp;
  }  // error: reference to 'var1' is ambiguous. 命名冲突
  void set_var2(int tmp) { var2 = tmp; }
  void set_var3(int tmp) { var3 = tmp; }
  void set_var4(int tmp) { var4 = tmp; }

 private:
  int var4;
};

int main() {
  Derive d;
  return 0;
}
