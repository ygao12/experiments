/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128, -1);
        int ans = 0, p = -1;
        for (int i = 0; i < (int)s.size(); ++i) {
          p = max(p, v[s[i]]);
          v[s[i]] = i;
          ans = max(ans, i - p);
        }
        return ans;
    }
};
// @lc code=end

