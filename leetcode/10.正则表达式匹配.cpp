/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool match(char c, char k) {
      return ((c == k) || k == '.');
    }
    bool isMatch(string s, string p) {
      s = " " + s;
      p = " " + p;
      int m = s.size(), n = p.size();
      bool dp[m + 1][n + 1];
      memset(dp, false, (m + 1) * (n + 1));
      dp[0][0] = true;
      for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (p[j - 1] == '*') {
            dp[i][j] = dp[i][j - 2];
            if (match(s[i - 1], p[j - 2])) {
              dp[i][j] |= dp[i - 1][j];
            }
          } else {
            if (match(s[i - 1], p[j - 1])) {
              dp[i][j] = dp[i - 1][j - 1];
            }
          }
        }
      }
      return dp[m][n];
    }
};
// @lc code=end

