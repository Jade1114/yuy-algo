/*
 * @lc app=leetcode id=113 lang=c
 *
 * [113] Path Sum II
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

void dfs(struct TreeNode* curr, int targetSum, int currentSum, int* path, int pathSize,
         int* returnSize, int** res, int** returnColumnSizes) {
  if (curr == NULL)
    return;

  path[pathSize] = curr->val;
  pathSize++;

  currentSum += curr->val;

  if (curr->left == NULL && curr->right == NULL) {
    if (currentSum == targetSum) {
      int* onePath = malloc(pathSize * sizeof(int));
      memcpy(onePath, path, pathSize * sizeof(int));
      res[*returnSize] = onePath;
      (*returnColumnSizes)[*returnSize] = pathSize;
      (*returnSize)++;
    }
  }

  dfs(curr->left, targetSum, currentSum, path, pathSize, returnSize, res, returnColumnSizes);
  dfs(curr->right, targetSum, currentSum, path, pathSize, returnSize, res, returnColumnSizes);

  pathSize--;
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
  int** res = malloc(1000 * sizeof(int*));
  *returnColumnSizes = malloc(1000 * sizeof(int));
  *returnSize = 0;

  int path[1000];

  dfs(root, targetSum, 0, path, 0, returnSize, res, returnColumnSizes);

  return res;
}
// @lc code=end
