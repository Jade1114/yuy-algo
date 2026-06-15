/*
 * @lc app=leetcode id=203 lang=c
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
  struct ListNode dummy;
  dummy.next = head;
  struct ListNode* curr = &dummy;
  while (curr->next != NULL) {
    if (curr->next->val == val) {
      curr->next = curr->next->next;
    } else {
      curr = curr->next;
    }
  }

  return dummy.next;
}
// @lc code=end
