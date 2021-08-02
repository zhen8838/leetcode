#include "commom.hpp"
#include <gtest/gtest.h>

/* 
# 元函数介绍 

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

/* 
## 类型元函数
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
  ic(std::is_same<decltype(a), uint64_t>::value);
}

/* 
# 各种元函数表示方法
*/

template <int a>
constexpr int no_struct_fun = a + 1; // NOTE 这样也可以是一个元函数,是不是很神奇, 不过他这样只能有一个返回值

template <int a>
struct struct_fun // NOTE 结构体的好处就是可以保存多个返回值
{
  using type = int;
  using ref_type = int &;
  using const_ref_type = const int &;
  constexpr static size_t size = sizeof(int);
};

/* 
## 模板类型参数与容器模板

  模板元编程最重要的就是把类型也看作是一种数据,要知道我们编写的程序在编译时必然被编译器存储,那么代码的类型也是一种变量存储在编译器中的,因此我们合理地调用类型数据,可以发挥更大的作用.
 */

/* 

###  模板作为元函数的输入

  NOTE 我们可以传入一个模版类型,这个模板类型可以接收多个一个或多个模板类型的,此时对应的数学表达式类似于: Fun(T_1,t_2)=T_1(t_2)
*/

template <template <typename> class T1, typename T2>
struct TypeCall_
{
  using type = typename T1<T2>::type;
};
template <template <typename> class T1, typename T2>
using TypeCall = typename TypeCall_<T1, T2>::type;

TEST(chapter1, _1_2_1)
{
  TypeCall<std::remove_reference, int &> h = 3;
  ic(h);
}

/* 
### 模板作为元函数的输出
  
  NOTE 其实我个人觉得这只能算是多个元函数的compose,元函数中很
*/

template <int AddorRemoveRef>
struct OptFunc_;

template <>
struct OptFunc_<0>
{
  template <typename T>
  using type = std::add_lvalue_reference<T>;
};

template <>
struct OptFunc_<1>
{
  template <typename T>
  using type = std::remove_reference<T>;
};

template <typename T, int AddorRemoveRef>
using OptFunc = typename OptFunc_<AddorRemoveRef>::template type<T>;

TEST(chapter1, _1_2_2)
{
  OptFunc<int, 1>::type h = 1;
  ic(h);
}

/* 
### 容器模板

容器模板就是一种可以保存数值数据或者类型数据的一个容器.他就是一个类型,但是他可以保存以上两种数据.
*/

template <int... Vals>
struct IntContainer
{
  // NOTE 即IntContainer这个类型中存储了一系列int值
};

template <typename... Types>
struct TypeContainer
{
  // NOTE 存储了一系列类型
};

// 以下两个是比较复杂的情况, ①保存了一系列的模板类型
template <template <typename> typename... Types>
struct TemplateContainer
{
};

template <template <typename...> typename... Types>
struct TemplateContainer2
{
};

/* 
## 编译期实现分支、循环
*/

/* 
### 典型的顺序执行元函数
*/
template <typename T>
struct RemoveCV_
{
private:
  using inner_type = typename std::remove_reference<T>::type;

public:
  using type = typename std::remove_reference<inner_type>::type;
};

template <typename T>
using RemoveCV = typename RemoveCV_<T>::type;

TEST(chapter1, _1_3_1)
{
  RemoveCV<const int &> h = 1;
  ic(h);
}

/* 
### 分支执行的代码

NOTE 其实分支执行的方式有好多,我自己都能写出好几个,但是找到一个比较通用优雅的写法可能还挺难
*/

// 1. 通过conditional实现分支, 这种方法就是用在结构体模板继承时使用的(通过选择来继承类型,然后得到当前的值)
template <int T>
struct IsOdd_ : std::conditional_t<(T % 2) == 1, std::true_type, std::false_type>
{
};

template <int T>
constexpr bool IsOdd = IsOdd_<T>::value;

// 2. 通过特化匹配来实现分支,比如我们设计了一个isfloat结构体,默认都是false,通过类型分发的可以自定义不同类型是否是float.

template <typename T>
struct isFloat_ : std::false_type
{
};

template <>
struct isFloat_<float> : std::true_type
{
};

template <>
struct isFloat_<uint64_t> : std::true_type
{
};

template <typename T>
constexpr auto isFloat = isFloat_<T>::value;

// 3. std::enable_if来实现分支,这个是比较好用的,下面就是一个简单的应用. 首先利用enable_if来匹配当前参数的大致类型,然后对于array类型,写了一个traits去获得他的size,然后再for循环.这其实就是任意类型打印的雏形了.
template <typename T>
struct is_array : std::false_type
{
};
template <typename T, size_t N>
struct is_array<std::array<T, N>> : std::true_type
{
};

template <typename T>
constexpr bool is_array_v = is_array<T>::value;

template <typename T>
struct array_traits
{
};
template <typename T, size_t N>
struct array_traits<std::array<T, N>>
{
  constexpr static size_t size = N;
};

template <typename T>
std::enable_if_t<is_array_v<T>, void> print_any(const T &v)
{
  std::cout << "arr :";
  for (size_t i = 0; i < array_traits<T>::size; i++)
  {
    std::cout << v[i] << " , ";
  }
  std::cout << std::endl;
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, void> print_any(const T &v)
{
  std::cout << "value :" << v << std::endl;
}

TEST(chapter1, _1_3_2)
{
  // 1
  ic(IsOdd<1>, IsOdd<2>);
  // 2
  ic(isFloat<float>, isFloat<uint64_t>, isFloat<double>);
  // 3
  std::array<float, 10> arr = {1, 2, 3, 4, 5, 6, 7};
  print_any(arr);
  print_any(true);
}

// 如果我们所有的操作都是在操作类型,我们可以用继承的方式把类型进行传递,这样就不需要中间变量.
// 当然在类型操作不足的时候,我们可以利用一些操作补足他们,比如下面这个例子就是先利用一个constexpr函数求值,此时这个值的类型是integral_constant类型,我们再decltype得到他的类型,再获取他的值.(这是个简单的例子,可能看不出这样有什么方便的)
template <size_t A, size_t B>
constexpr auto add()
{
  return std::integral_constant<size_t, A + B>();
}

template <size_t A, size_t B>
struct add_ : decltype(add<A, B>())
{
};

TEST(chapter1, question_1)
{
  ic(add_<1, 2>::value);
}

/* 
##  模板元函数的写法 1
*/

// 定义元函数的入参,这里表明这个结构体接收一个类型作为参数
template <typename T>
struct method_1
{
};

// 我们特化上面的那个元函数,通常特化直接写值,但是由于我们当前给的参数还依赖一个未知的`Value`,因此还需要给元函数再加一个模板类型.
template <size_t Value>
struct method_1<std::integral_constant<size_t, Value>>
{
  // 同时对于这个模板元的返回值也有两种方法,可以是一个静态的变量,也可以是对应的类型(此时那个类型其实也保存了值)
  constexpr static size_t one_v = Value + 1;
  using one_t = std::integral_constant<size_t, Value + 1>;
};

TEST(chapter1, question_2)
{
  auto a = method_1<std::integral_constant<size_t, 3>>::one_v;
  ic(a);
  auto b = method_1<std::integral_constant<size_t, 3>>::one_t::value;
  ic(b);
}