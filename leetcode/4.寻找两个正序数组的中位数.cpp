/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
  int findSmallK(vector<int> nums1, vector<int> nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    int l1 = 0, l2 = 0, current_k = k, i, j, half_k;
    while (true) {
      if (l1 == n1) {
        return nums2[l2 + current_k - 1];
      }
      if (l2 == n2) {
        return nums1[l1 + current_k - 1];
      }
      if (current_k == 1) {
        return min(nums1[l1], nums2[l2]);
      }
      int half_k = floor(current_k / 2);
      i = min(l1 + half_k, n1) - 1;
      j = min(l2 + half_k, n2) - 1;
      if (nums1[i] < nums2[j]) {
        current_k -= (i - l1 + 1);
        l1 = i + 1;
      } else {
        current_k -= (j - l2 + 1);
        l2 = j + 1;
      }
    }
  }

  double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
    int total_num = nums1.size() + nums2.size();
    if (total_num % 2 == 1) {
      return findSmallK(nums1, nums2, (total_num + 1) / 2) * 1.0;
    } else {
      return (findSmallK(nums1, nums2, total_num / 2) + findSmallK(nums1, nums2, total_num / 2 + 1)) / 2.0;
    }
  }

  double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2) {
      return findMedianSortedArrays(nums2, nums1);
    }
    int a1 = 0, a2 = 0, left = 0, right = n1 + 1, total = n1 + n2;
    int l1, r1, l2, r2, sma1, sma2;
    while (left <= right) {
      a1 = floor((right - left) / 2) + left;
      a2 = floor(total / 2) - a1;
      l1 = (a1 == 0) ? INT_MIN : nums1[a1 -1];
      r1 = (a1 == n1) ? INT_MAX : nums1[a1];
      l2 = (a2 == 0) ? INT_MIN : nums2[a2 -1];
      r2 = (a2 == n2) ? INT_MAX : nums2[a2];
      sma1 = max(l1, l2);
      sma2 = min(r1, r2);
      if (sma1 > sma2) {
        if (r1 < sma1) {
          left = a1;
        } else {
          right = a1;
        }
      } else {
        break;
      }
    }
    if (total % 2 == 0) {
      return (sma1 + sma2) / 2.0;
    }
    return max(sma1, sma2);
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int ttype(2);
    if (ttype == 1) {
      return findMedianSortedArrays1(nums1, nums2);
    } else {
      return findMedianSortedArrays2(nums1, nums2);
    }
  }
};
// @lc code=end

