/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> tmp;
      vector<int> res(2, 0);
      for (size_t t = 0; t < nums.size(); ++t) {
        int key = target - nums[t];
        if (tmp.find(key) != tmp.end()) {
          res[0] = tmp[key];
          res[1] = t;
          break;
        }
        tmp[nums[t]] = (int)t;
      }
      return res;
    }
};
// @lc code=end

