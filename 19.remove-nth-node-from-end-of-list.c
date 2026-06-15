/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  struct ListNode dummy;
  dummy.next = head;
  struct ListNode* slow = &dummy;
  struct ListNode* fast = &dummy;
  for (int i = 0; i <= n; i++) {
    fast = fast->next;
  }

  while (fast != NULL) {
    slow = slow->next;
    fast = fast->next;
  }

  slow->next = slow->next->next;

  return dummy.next;
}
// @lc code=end
