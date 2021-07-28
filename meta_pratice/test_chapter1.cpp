#include "commom.hpp"
#include <gtest/gtest.h>

/* 元函数介绍 
元函数会在编译期被调用与执行。在编译阶段,编译器只能构造常量作为其中间结果,无法构造并维护可以记录系统状态并随之改变的量,因此编译期可以使用的函数(即元函数)只能是无副作用的函数。
*/

constexpr int func(int a) { return a + 1; }
// NOTE 下面这个函数是随着调用次数改变输出的值,所以无法作为元函数.
// static int count = 3;
// constexpr int func(int a) { return a + (count++); }

TEST(chapter1, _1_1_1)
{
  // NOTE 此函数没有固定输入输出,所以可以同时作为编译期函数或运行时函数.
  constexpr int a = func(3);
  int b = 4;
  int c = func(b);
  ic(a, c);
}

/* 类型元函数
如果说上面的函数是操作 y=f(𝑥),那么他的输入是一个数值.但其实在c++中我们可以把类型看作是一种数值,对类型进行计算.
 */
template <typename T>
struct Func_
{
  using type = T;
};

template <>
struct Func_<int>
{
  using type = uint64_t;
};

template <>
struct Func_<uint32_t>
{
  using type = uint64_t;
};

// 不过上面的元函数表述方法太过繁琐,我们可以用更加简化的方式来调用,由于using的时候默认会认为你在声明namespace,所以需要加上typename修饰来表明这是一个类型.
template <typename T>
using Fun = typename Func_<T>::type;

TEST(chapter1, _1_1_2)
{
  // NOTE 我们构建的类型映射,把int 或者 uint32都转换到了uint64,然后利用比较他的类型是否和uint64相同.
  Fun<int> a = 0x1;
  ic(is_same<decltype(a), uint64_t>::value);
}

/* 各种元函数表示方法

 */

template <int a>
constexpr int no_struct_fun = a + 1; // NOTE 这样也可以是一个元函数,是不是很神奇, 不过他这样只能有一个返回值

template <int a>
struct struct_fun // NOTE 结构体的好处就是可以保存多个返回值
{
  using type = int;
  using ref_type = int &;
  using const_ref_type = const int &;
  constexpr size_t size = sizeof(int);
};
