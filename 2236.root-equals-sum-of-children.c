/*
 * @lc app=leetcode id=2236 lang=c
 *
 * [2236] Root Equals Sum of Children
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
bool checkTree(struct TreeNode* root) {
  return root->left->val + root->right->val == root->val;
}
// @lc code=end
