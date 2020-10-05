/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include "commom.hpp"

// @lc code=start
class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    map<char, int> set_s;
    if (s.size() != t.size())
      return false;
    for (size_t i = 0; i < s.size(); i++)
    {
      set_s[s[i]] += 1;
      set_s[t[i]] -= 1;
      if (set_s[s[i]] == 0)
        set_s.erase(s[i]);
      if (set_s[t[i]] == 0)
        set_s.erase(t[i]);
    }

    return set_s.size() == 0;
  }
};
// @lc code=end

int main(int argc, char const *argv[])
{
  string s = "acca", t = "acac";
  auto sol = Solution();
  auto out = sol.isAnagram(s, t);
  cout << out << endl;
  return 0;
}
