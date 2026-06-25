/*
 * @lc app=leetcode id=112 lang=c
 *
 * [112] Path Sum
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
bool dfs(struct TreeNode* curr, int targetSum, int currentSum) {
  int sum = curr->val + currentSum;
  if (curr->left == NULL && curr->right == NULL) {
    if (sum == targetSum) {
      return true;
    } else {
      return false;
    }
  }
  bool left = false;
  bool right = false;

  if (curr->left != NULL)
    left = dfs(curr->left, targetSum, sum);
  if (curr->right != NULL)
    right = dfs(curr->right, targetSum, sum);

  return left || right;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
  if (root == NULL) {
    return false;
  }

  return dfs(root, targetSum, 0);
}
// @lc code=end
