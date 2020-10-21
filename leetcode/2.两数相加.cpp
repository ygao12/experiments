/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *tmp = nullptr;
      if (l1 == nullptr && l2 == nullptr) {
        return tmp;
      }
      tmp = new ListNode();
      ListNode *res = tmp;
      bool adv(false);
      while (tmp != nullptr) {
        if (l1 != nullptr) {
          tmp->val += l1->val;
          l1 = l1->next;
        }
        if (l2 != nullptr) {
          tmp->val += l2->val;
          l2 = l2->next;
        }
        if (adv) tmp->val += 1;
        if (tmp->val >= 10) {
          adv = true;
          tmp->val -= 10;
        } else {
          adv = false;
        }
        if (l1 != nullptr || l2 != nullptr || adv) {
          tmp->next = new ListNode();
        }
        tmp = tmp->next;
      }
      return res;
    }
};
// @lc code=end

