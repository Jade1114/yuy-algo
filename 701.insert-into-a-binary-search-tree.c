/*
 * @lc app=leetcode id=701 lang=c
 *
 * [701] Insert into a Binary Search Tree
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
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
  if (root == NULL) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
  }

  if (val < root->val) {
    root->left = insertIntoBST(root->left, val);
  }

  if (val > root->val) {
    root->right = insertIntoBST(root->right, val);
  }

  return root;
}
// @lc code=end
