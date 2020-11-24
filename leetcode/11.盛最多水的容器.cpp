/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
      int l(0), r(height.size() - 1);
      int max_vol(-1);
      while (l < r) {
        max_vol = max((r - l) * min(height[r], height[l]), max_vol);
        if (height[r] < height[l]) {
          --r;
        } else {
          ++l;
        }
      }
      return max_vol;
    }
};
// @lc code=end

