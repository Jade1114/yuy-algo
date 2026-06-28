/*
 * @lc app=leetcode id=234 lang=c
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
  struct ListNode* prev = NULL;
  struct ListNode* curr = head;

  while (curr != NULL) {
    struct ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

bool isPalindrome(struct ListNode* head) {

  if (head == NULL || head->next == NULL) {
    return true;
  }

  struct ListNode* slow = head;
  struct ListNode* fast = head;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }

  struct ListNode* second = reverseList(slow);

  struct ListNode* p1 = head;
  struct ListNode* p2 = second;

  while (p2 != NULL) {
    if (p1->val != p2->val) {
      return false;
    }

    p1 = p1->next;
    p2 = p2->next;
  }
  return true;
}
// @lc code=end
