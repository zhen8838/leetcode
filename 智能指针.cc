#include <memory>

#include "commom.hpp"

class Report {
 private:
  string str;

 public:
  Report(const string s) : str(s) { cout << "object create" << endl; }
  ~Report() { cout << "object decreate" << endl; }
  void comment() { ic(str); }
};

int main(int argc, char const* argv[]) {
  {
    auto_ptr<Report> ps(new Report("auto_ptr"));
    ps->comment();
  }
  {
    shared_ptr<Report> ps(new Report("shared_ptr"));
    ps->comment();
  }
  {
    unique_ptr<Report> ps(new Report("unique_ptr"));
    ps->comment();
  }

  return 0;
}
