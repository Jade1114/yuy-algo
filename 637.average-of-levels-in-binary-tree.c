/*
 * @lc app=leetcode id=637 lang=c
 *
 * [637] Average of Levels in Binary Tree
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
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
  double* res = malloc(10000 * sizeof(double));

  struct TreeNode* queue[10000];
  int front = 0;
  int rear = 0;
  *returnSize = 0;

  queue[rear++] = root;

  while (front < rear) {
    int levelSize = rear - front;
    double sum = 0;

    for (int i = 0; i < levelSize; i++) {

      struct TreeNode* node = queue[front++];

      sum += node->val;

      if (node->left != NULL) {
        queue[rear++] = node->left;
      }
      if (node->right != NULL) {
        queue[rear++] = node->right;
      }
    }

    res[*returnSize] = sum / levelSize;
    (*returnSize)++;
  }

  return res;
}
// @lc code=end
