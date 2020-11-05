/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
      int ret(0);
      int val = x;
      while (val != 0) {
        int mod = val % 10;
        val /= 10;
        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && mod > 7)) {
          return 0;
        }
        if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && mod < -8)) {
          return 0;
        }
        ret = ret * 10 + mod;
      }
      return ret;
    }
};
// @lc code=end

