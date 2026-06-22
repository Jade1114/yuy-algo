/*
 * @lc app=leetcode id=515 lang=c
 *
 * [515] Find Largest Value in Each Tree Row
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
  *returnSize = 0;
  if (root == NULL) {
    return NULL;
  }

  int* res = malloc(10000 * sizeof(int));
  struct TreeNode* queue[10001];
  int front = 0;
  int rear = 0;
  queue[rear++] = root;

  while (front < rear) {
    int levelSize = rear - front;
    int max = INT_MIN;

    for (int i = 0; i < levelSize; i++) {
      struct TreeNode* curr = queue[front++];

      if (curr->val > max) {
        max = curr->val;
      }

      if (curr->left != NULL) {
        queue[rear++] = curr->left;
      }

      if (curr->right != NULL) {
        queue[rear++] = curr->right;
      }
    }
    res[*returnSize] = max;
    (*returnSize)++;
  }

  return res;
}
// @lc code=end
