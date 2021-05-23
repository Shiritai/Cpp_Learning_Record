/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
        int carry_out = (l1->val + l2->val) / 10, tmp = 0;
        ListNode * head = new ListNode((l1->val + l2->val) % 10);
        ListNode * cur = head;
        l1 = l1->next, l2 = l2->next;
        while (l1 != NULL && l2 != NULL){
            tmp = l1->val + l2->val + carry_out;
            cur->next = new ListNode(tmp % 10);
            carry_out = tmp / 10;
            cur = cur->next;
            l1 = l1->next, l2 = l2->next;
        }
        while (l1 != NULL){
            tmp = l1->val + carry_out;
            cur->next = new ListNode(tmp % 10);
            carry_out = tmp / 10;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2 != NULL){
            tmp = l2->val + carry_out;
            cur->next = new ListNode(tmp % 10);
            carry_out = tmp / 10;
            cur = cur->next;
            l2 = l2->next;
        }
        if (carry_out)
            cur->next = new ListNode(carry_out);
        return head;
    }
};
// @lc code=end

