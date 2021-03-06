#include <iostream>
using namespace std;
class Base {
 public:
  void func1() { cout << "func1" << endl; }
  virtual void B_func1() { cout << "B_func1" << endl; }
  virtual void B_func2() { cout << "B_func2" << endl; }
};

class Derive : public Base {
 public:
  virtual void D_func1() { cout << "D_func1" << endl; }
  virtual void D_func2() { cout << "D_func2" << endl; }
};
class CC : public Base {
 public:
  void func1() { cout << "CC_func1" << endl; }
  virtual void C_func1() { cout << "C_func1" << endl; }
  virtual void C_func2() { cout << "C_func2" << endl; }
};

/*

*构造函数不能定义为虚函数，原因：
! 不定义出对象我们就没法访问他的虚函数表,但是不访问虚函数表我们就没法构造类对象

*析构函数一般定义为虚函数，原因：
!
如果我们要使用多态的用法时,基类的指针会指向派生类,如果不是虚函数,默认会执行基类的析构方法,这个时候万一派生类的资源没有回收就出大问题了

class T {
 public:
  virtual T() { cout << "T!" << endl; }
};
*/

/* 如果虚函数没有被覆盖,那么就是执行原始的方法 */
int main() {
  Base* b = new Derive();
  b->B_func1();
  Base* c = new CC();
  c->func1();
  delete b, c;
  // T* t = new T();
  // delete t;
}
