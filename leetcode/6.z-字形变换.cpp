/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
      if (numRows == 1) {
        return s;
      }
      string ret;
      int n = s.size();
      int incr = 2 * numRows - 2;
      for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j + i < n; j += incr) {
          ret += s[i + j];
          if (i != 0 && i != numRows - 1 && j + incr - i < n) {
            ret += s[j + incr - i];
          }
        }
      }
      return ret;
    }
};
// @lc code=end

