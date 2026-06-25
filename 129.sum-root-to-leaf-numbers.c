/*
 * @lc app=leetcode id=129 lang=c
 *
 * [129] Sum Root to Leaf Numbers
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
void dfs(struct TreeNode* curr, int currSum, int* sum) {

  if (curr == NULL)
    return;

  currSum = currSum * 10 + curr->val;

  if (curr->left == NULL && curr->right == NULL) {
    *sum += currSum;
    return;
  }

  dfs(curr->left, currSum, sum);
  dfs(curr->right, currSum, sum);
}

int sumNumbers(struct TreeNode* root) {
  int sum = 0;
  dfs(root, 0, &sum);
  return sum;
}
// @lc code=end
