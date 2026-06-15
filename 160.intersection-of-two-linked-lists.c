/*
 * @lc app=leetcode id=160 lang=c
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
  struct ListNode* a = headA;
  struct ListNode* b = headB;
  int lenA = 0;
  int lenB = 0;

  while (a != NULL) {
    a = a->next;
    lenA++;
  }

  while (b != NULL) {
    b = b->next;
    lenB++;
  }

  a = headA;
  b = headB;

  while (lenA > lenB) {
    a = a->next;
    lenA--;
  }

  while (lenB > lenA) {
    b = b->next;
    lenB--;
  }

  while (a != b) {
    a = a->next;
    b = b->next;
  }

  return a;
}
// @lc code=end
