#include <gtest/gtest.h>

#include <commom.hpp>

class StrBlob {
 public:
  shared_ptr<vector<string>> data;

  StrBlob() : data(make_shared<vector<string>>()){};
  StrBlob(initializer_list<string> il)
      : data(make_shared<vector<string>>(il)){};
  size_t size() { return data->size(); };
  size_t use_count() { return data.use_count(); };

  const string& front() {
    check(0, "front");
    return data->front();
  }
  const string& back() {
    check(0, "back");
    return data->back();
  }
  void push_back(const string& s) { data->push_back(s); }
  void pop_back() {
    check(0, "pop_back");
    data->pop_back();
  }

  void combine(StrBlob sb) {
    for (auto p = sb.data->begin(); p != sb.data->end(); p++)
      data->push_back(*p);
  }

 private:
  void check(size_t i, const string& msg) const {
    if (i >= data->size()) { throw out_of_range(msg); }
  }
};

TEST(test, shared_ptr_copy) {
  auto p = make_shared<int>(10);
  {
    auto q = make_shared<int>(11);
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
    cout << b1.use_count() << endl;
    b1 = b2;
    cout << b1.use_count() << endl;
    cout << b2.use_count() << endl;
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
  return make_shared<vector<int>>(initializer_list<int>{1, 2, 3});
}
void read_vector(shared_ptr<vector<int>> v) { v->push_back(12); }
void print_vector(shared_ptr<vector<int>> v) { ic(*v); }

TEST(test, shared_ptr_construt) {
  auto a = shared_ptr<int>(new int(32));
  ic(*a);
  auto b = make_shared<vector<int>>(10, 20);
  ic(*b);
}

TEST(test, t_12_6) {
  shared_ptr<vector<int>> p = create_vector();
  read_vector(p);
  print_vector(p);
}
