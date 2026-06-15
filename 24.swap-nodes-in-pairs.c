/*
 * @lc app=leetcode id=24 lang=c
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
  struct ListNode dummy;
  dummy.next = head;
  struct ListNode* prev = &dummy;

  while (prev->next != NULL && prev->next->next != NULL) {
    struct ListNode* node1 = prev->next;
    struct ListNode* node2 = prev->next->next;

    prev->next = node2;
    node1->next = node2->next;
    node2->next = node1;
    prev = node1;
  }

  return dummy.next;
}
// @lc code=end
