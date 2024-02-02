/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 *
 * [2660] 保龄球游戏的获胜者
 */
#include "commom.hpp"
using namespace std;

// @lc code=start
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        auto res = getScore(player1) - getScore(player2);   
        if (res < 0)
          return 2;
        else if(res > 0)
          return 1;
        return 0;
    }

    int getScore(vector<int> &player){
      int score = 0;
      int bonusJ = -2;
      for (int i = 0; i < player.size(); i++) {
        score += player[i];
        if (bonusJ >= 0 && (i - bonusJ) <= 2) {
          score += player[i];
        }

        if (player[i] == 10)
          bonusJ = i;
      }
      return score;
    }
};
// @lc code=end

int main() {
  vector<int> a = {10,2,2,3};
  vector<int> b = {3,8,4,5};
  Solution s;
  auto x = s.isWinner(a,b);
  cout << x << endl;
}