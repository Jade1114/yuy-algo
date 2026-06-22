/*
 * @lc app=leetcode id=199 lang=c
 *
 * [199] Binary Tree Right Side View
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
int* rightSideView(struct TreeNode* root, int* returnSize) {
  *returnSize = 0;

  if (root == NULL) {
    return NULL;
  }

  int* res = malloc(100 * sizeof(int));
  struct TreeNode* queue[101];
  int front = 0;
  int rear = 0;

  queue[rear++] = root;

  while (front < rear) {
    int levelSize = rear - front;

    for (int i = 0; i < levelSize; i++) {
      struct TreeNode* curr = queue[front++];

      if (i == levelSize - 1) {
        res[*returnSize] = curr->val;
        (*returnSize)++;
      }

      if (curr->left != NULL) {
        queue[rear++] = curr->left;
      }

      if (curr->right != NULL) {
        queue[rear++] = curr->right;
      }
    }
  }

  return res;
}
// @lc code=end
