/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
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
int maxDepth(struct TreeNode* root) {
  if (root == NULL) {
    return 0;
  }

  int left = 1 + maxDepth(root->left);
  int right = 1 + maxDepth(root->right);

  return left > right ? left : right;
}
// @lc code=end
