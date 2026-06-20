/*
 * @lc app=leetcode id=107 lang=c
 *
 * [107] Binary Tree Level Order Traversal II
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
  int** res = malloc(2000 * sizeof(int*));
  *returnColumnSizes = malloc(2000 * sizeof(int));
  *returnSize = 0;

  if (root == NULL) {
    return res;
  }

  struct TreeNode* queue[2000];
  int front = 0;
  int rear = 0;

  queue[rear++] = root;

  while (front < rear) {
    int levelSize = rear - front;

    res[*returnSize] = malloc(levelSize * sizeof(int));
    (*returnColumnSizes)[*returnSize] = levelSize;

    for (int i = 0; i < levelSize; i++) {
      struct TreeNode* node = queue[front++];

      res[*returnSize][i] = node->val;

      if (node->left != NULL) {
        queue[rear++] = node->left;
      }

      if (node->right != NULL) {
        queue[rear++] = node->right;
      }
    }

    (*returnSize)++;
  }

  int left = 0;
  int right = *returnSize - 1;

  while (left < right) {
    int* tempRow = res[left];
    res[left] = res[right];
    res[right] = tempRow;

    int tempCol = (*returnColumnSizes)[left];
    (*returnColumnSizes)[left] = (*returnColumnSizes)[right];
    (*returnColumnSizes)[right] = tempCol;

    left++;
    right--;
  }

  return res;
}
// @lc code=end
