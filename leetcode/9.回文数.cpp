/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      if (x > 0 && x % 10 == 0) return false;
      int val(x);
      int ret(0);
      while (val > ret) {
        int mod = val % 10;
        val /= 10;
        ret = ret * 10 + mod;
      }
      if (ret == val || ret / 10 == val) {
        return true;
      }
      return false;
    }
};
// @lc code=end

