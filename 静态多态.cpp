#include "commom.hpp"
namespace StaticPoly {
class Base {
 public:
  virtual void Draw() const {};
};
class Line : public Base {
 public:
  void Draw() const { std::cout << "Line Draw()\n"; }
};

class Circle : public Base {
 public:
  void Draw(const char* name = NULL) const { std::cout << "Circle Draw()\n"; }
};

class Rectangle : public Base {
 public:
  void Draw(int i = 0) const { std::cout << "Rectangle Draw()\n"; }
};

template <typename Geometry>
void DrawGeometry(const Geometry& geo) {
  geo.Draw();
}

template <typename Geometry>
void DrawGeometry(std::vector<Geometry> vecGeo) {
  const size_t size = vecGeo.size();
  for (size_t i = 0; i < size; ++i) vecGeo[i].Draw();
}
}  // namespace StaticPoly

void test_static_polymorphism() {
  StaticPoly::Line line;
  StaticPoly::Circle circle;
  StaticPoly::Rectangle rect;
  StaticPoly::DrawGeometry(circle);
  StaticPoly::DrawGeometry(rect);

  std::vector<StaticPoly::Line> vecLines;
  StaticPoly::Line line2;
  StaticPoly::Line line3;
  vecLines.push_back(line);
  vecLines.push_back(line2);
  vecLines.push_back(line3);
  // vecLines.push_back(&circle); //编译错误，已不再能够处理异质对象
  // vecLines.push_back(&rect);    //编译错误，已不再能够处理异质对象
  StaticPoly::DrawGeometry(vecLines);

  std::vector<StaticPoly::Circle> vecCircles;
  vecCircles.push_back(circle);
  StaticPoly::DrawGeometry(circle);
}

void test_dynamic() {
  StaticPoly::Base* p;
  StaticPoly::Line line;
  StaticPoly::Circle circle;
  StaticPoly::Rectangle rect;
  /*
  ! class 默认的继承方式是private,如果直接继承那么没法访问基类的元素
  ! class 动态多态的时候一定要注意虚函数所有的名字都必须一样
  */
  p = &line;
  p->Draw();
  p = &circle;
  p->Draw();
  p = &rect;
  p->Draw();
  StaticPoly::Base* pl = new StaticPoly::Line();
  pl->Draw();
  delete pl;
}
extern "C" {
#define Second (60UL * 60 * 24 * 3600)
}

void test_vector() {
  vector<int> a{1, 2, 4};
  vector<int>::iterator p = a.begin();
  // a.insert(p, 3);
  a.insert(a.begin(), 3);
  // ic(*p);
  ic(a);
}

// void test_sizeof() {
//   auto lambda = [](char b[10]) {
//     // 不管有没有指定长度，都是指针大小
//     ic(sizeof(b));
//     ic(strlen(b));
//   };
//   char a[10] = "asss";
//   ic(sizeof(a));
//   lambda(a);
// }

void test_class_size() {
  class empty {
   private:
    /* data */
   public:
    empty(/* args */){};
    virtual void doa(){};
    virtual void dob(){};
  };
  empty e;
  ic(sizeof(e));
}

class ss2 {
 public:
  static int a;  // 静态成员变量的内存不被类计算在内
};
int ss2::a = 1;

void test_struct_size() {
  struct ss {
    int a;
    int b[];
  };
  ic(sizeof(ss));  // 4

  ic(sizeof(ss2));    // 4
  ic(sizeof(ss2()));  // 4
}

void 测试大小端() {
  int a = 0x12;
  ic(static_cast<char>(a) == a);
  union tt {
    int a;
    char b;
  };
  tt t;
  t.a = 0x12;
  ic(bitset<16>(t.b));
}

void 测试异或() {
  vector<int> nums{1, 0, 0, 1, 0};
  int x = 0;
  for (auto&& i : nums) { x ^= i; }
  ic(x);
}

int main(int argc, char const* argv[]) {
  // test_static_polymorphism();
  // test_dynamic();
  // cout << Second << endl;
  // ic(sizeof(short));
  // test_vector();
  // test_sizeof();
  // test_class_size();
  // test_struct_size();
  // 测试大小端();
  测试异或();
  return 0;
}
