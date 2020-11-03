/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution1 {
public:
    pair<int, int> expand(string &s, int left, int right) {
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
      }
      return {left + 1, right - 1};
    }
    string longestPalindrome(string s) {
      int start = 0, end = 0;
      for (int i = 0; i < (int)s.size(); ++i) {
        auto [l1, r1] = expand(s, i, i);
        auto [l2, r2] = expand(s, i, i + 1);
        if (r1 - l1 > end - start) {
          start = l1;
          end = r1;
        }
        if (r2 - l2 > end - start) {
          start = l2;
          end = r2;
        }
      }
      return s.substr(start, end - start + 1);
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
      bool **dp = new bool*[s.size()];
      for (int i = 0; i < (int)s.size(); ++i) {
        dp[i] = new bool[i];
      }
      int start(0), max_len(1);
      for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
          if (s[i] == s[j] && (i - j < 3 || dp[i - 1][j + 1])) {
            dp[i][j] = true;
          } else {
            dp[i][j] = false;
          }
          if (dp[i][j] && i - j + 1 > max_len) {
            start = j;
            max_len = i - j + 1;
          }
        }
      }
      for (int i = 0; i < (int)s.size(); ++i) {
        delete[] dp[i];
      }
      delete[] dp;
      return s.substr(start, max_len);
    }
};

class Solution {
public:
    int expand(string &s, int left, int right) {
      int start(left), end(right);
      while (start >= 0 && end < s.size() && s[start] == s[end]) {
        --start;
        ++end;
      }
      return (end - start - 2) / 2;
    }
    string longestPalindrome(string s) {
      string ss("#");
      for (auto c : s) {
        ss += c;
        ss += '#';
      }
      vector<int> arm_len;
      int cent(-1), front(-1);
      int start(0), end(0);
      for (int i = 0; i < (int)ss.size(); ++i) {
        int cur_len(0);
        if (front >= i) {
          int i_sym = 2 * cent - i;
          int min_arm = min(arm_len[i_sym], front - i);
          cur_len = expand(ss, i - min_arm, i + min_arm);
        } else {
          cur_len = expand(ss, i, i);
        }
        arm_len.push_back(cur_len);
        if (i + cur_len > front) {
          cent = i;
          front = cent + cur_len;
        }
        if (2 * cur_len + 1 > end - start) {
          start = i - cur_len;
          end = i + cur_len;
        }
      }
      string ret;
      for (int i = start; i < end; ++i) {
        if (ss[i] != '#') {
          ret += ss[i];
        }
      }
      return ret;
    }
};
// @lc code=end

