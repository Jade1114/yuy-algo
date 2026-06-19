/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
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

int getHeight(struct TreeNode* root) {
  if (root == NULL)
    return 0;
  int left = getHeight(root->left);
  int right = getHeight(root->right);

  if (left == -1 || right == -1) {
    return -1;
  }

  if (left - right > 1 || right - left > 1) {
    return -1;
  }

  return fmax(left, right) + 1;
}

bool isBalanced(struct TreeNode* root) {
  return getHeight(root) != -1;
}
// @lc code=end
