/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class AutoM {
  int state = 0;
  int state_table[4][4] = {
    {0, 1, 2, 3},
    {3, 3, 2, 3},
    {3, 3, 2, 3},
    {3, 3, 3, 3}
  };
  int translate(char c) {
    if (isdigit(c)) return 2;
    if (isspace(c)) return 0;
    if (c == '+' || c == '-') return 1;
    return 3;
  }
 public:
  long long ans = 0;
  int sign = 1;
  bool stop = false;
  void process(char c) {
    state = state_table[state][translate(c)];
    if (state == 2) {
      ans = ans * 10 + c - '0';
      if (sign == 1 && ans > (long long)INT_MAX) {
        stop = true;
        ans = INT_MAX;
      } else if (sign == -1 && -ans < (long long)INT_MIN) {
        stop = true;
        ans = INT_MIN;
      }
    } else if (state == 1) {
      sign = c == '+' ? 1 : -1;
    } else if (state == 3) {
      stop = true;
    }
  }
  int run(string &s) {
    for (char c : s) {
      process(c);
      if (stop) {
        break;
      }
    }
    return ans * sign;
  }
};

class Solution {
public:
    int myAtoi(string s) {
      AutoM autom;
      return autom.run(s);
    }
};
// @lc code=end

