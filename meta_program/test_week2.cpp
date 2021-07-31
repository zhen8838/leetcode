#include "commom.hpp"
#include <gtest/gtest.h>

class Object
{
private:
  std::string name;

public:
  Object(std::string new_name) : name(new_name) {}
  void operator=(Object other)
  {
    name = other.name;
  }
  const std::string &get_name() const
  {
    return name;
  }
};

std::ostream &operator<<(std::ostream &os, const Object &obj)
{
  os << obj.get_name();
  return os;
}

template <typename Iter>
void swap_iter(Iter a, Iter b)
{
  typename std::iterator_traits<Iter>::value_type c = *a;
  *a = *b;
  *b = c;
}

TEST(test, chapter_2_1_1)
{
  std::vector<int> arr{1, 2, 3, 4};
  // 对于原生迭代器,可以方便的获取他的value type
  ic(arr);
  swap_iter(arr.begin(), arr.begin() + 1);
  ic(arr);
}

// NOTE 我们可以利用type traits给Object对象添加swap的适配
template <>
struct std::iterator_traits<Object *>
{
  typedef Object value_type;
};

TEST(test, chapter_2_1_2)
{
  Object a("12"), b("23");
  // 对于原生迭代器,可以方便的获取他的value type
  ic(a, b);
  swap_iter(&a, &b);
  ic(a, b);
}