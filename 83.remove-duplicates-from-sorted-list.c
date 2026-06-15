/*
 * @lc app=leetcode id=83 lang=c
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
  if (head == NULL)
    return NULL;

  struct ListNode* curr = head;

  while (curr->next != NULL) {
    if (curr->val == curr->next->val) {
      curr->next = curr->next->next;
    } else {
      curr = curr->next;
    }
  }

  return head;
}

// @lc code=end
