#include <gtest/gtest.h>

#include <commom.hpp>

class StrBlob {
 public:
  std::shared_ptr<std::vector<std::string>> data;

  StrBlob() : data(std::make_shared<std::vector<std::string>>()){};
  StrBlob(std::initializer_list<std::string> il)
      : data(std::make_shared<std::vector<std::string>>(il)){};
  size_t size() { return data->size(); };
  size_t use_count() { return data.use_count(); };

  const std::string& front() {
    check(0, "front");
    return data->front();
  }
  const std::string& back() {
    check(0, "back");
    return data->back();
  }
  void push_back(const std::string& s) { data->push_back(s); }
  void pop_back() {
    check(0, "pop_back");
    data->pop_back();
  }

  void combine(StrBlob sb) {
    for (auto p = sb.data->begin(); p != sb.data->end(); p++)
      data->push_back(*p);
  }

 private:
  void check(size_t i, const std::string& msg) const {
    if (i >= data->size()) { throw std::out_of_range(msg); }
  }
};

TEST(test, shared_ptr_copy) {
  auto p = std::make_shared<int>(10);
  {
    auto q = std::make_shared<int>(11);
    p = q;
    ic(*q, q.use_count());
    ic(*p, p.use_count());
  }
  ic(*p, p.use_count());
}

TEST(test, t_12_1) {
  StrBlob b1;
  {
    StrBlob b2 = {"a", "bc", "de"};
    std::cout << b1.use_count() << std::endl;
    b1 = b2;
    std::cout << b1.use_count() << std::endl;
    std::cout << b2.use_count() << std::endl;
    b2.push_back("fg");
    ic(*b1.data);
    ic(*b2.data);
  }
  ic(*b1.data);
}

TEST(test, t_12_5) {
  StrBlob b1{"1", "2", "3"};
  ic(*b1.data);
  b1.combine({"4", "5", "6"});
  ic(*b1.data);
}

auto create_vector() {
  return std::make_shared<std::vector<int>>(std::initializer_list<int>{1, 2, 3});
}
void read_vector(std::shared_ptr<std::vector<int>> v) { v->push_back(12); }
void print_vector(std::shared_ptr<std::vector<int>> v) { ic(*v); }

TEST(test, shared_ptr_construt) {
  auto a = std::shared_ptr<int>(new int(32));
  ic(*a);
  auto b = std::make_shared<std::vector<int>>(10, 20);
  ic(*b);
}

TEST(test, t_12_6) {
  std::shared_ptr<std::vector<int>> p = create_vector();
  read_vector(p);
  print_vector(p);
}
