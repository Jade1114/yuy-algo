/*
 * @lc app=leetcode id=116 lang=c
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
  if (root == NULL) {
    return NULL;
  }

  struct Node* queue[5000];
  int front = 0;
  int rear = 0;

  queue[rear++] = root;

  while (front < rear) {
    int levelSize = rear - front;

    for (int i = 0; i < levelSize; i++) {
      struct Node* curr = queue[front++];

      if (i == levelSize - 1) {
        curr->next = NULL;
      } else {
        struct Node* next = queue[front];
        curr->next = next;
      }

      if (curr->left != NULL)
        queue[rear++] = curr->left;
      if (curr->right != NULL)
        queue[rear++] = curr->right;
    }
  }

  return root;
}
// @lc code=end
