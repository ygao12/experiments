/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
      int k[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
      string v[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
      string ret;
      int cur(num);
      int len = 13;
      for (int i = len - 1; i >= 0; --i) {
        if (cur == 0) break;
        int cnt = cur / k[i];
        cur = cur % k[i];
        for (int j = 0; j < cnt; ++j) {
          ret += v[i];
        }
      }
      return ret;
    }
};
// @lc code=end

