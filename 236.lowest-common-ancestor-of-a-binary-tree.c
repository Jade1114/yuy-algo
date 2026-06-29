/*
 * @lc app=leetcode id=236 lang=c
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p,
                                      struct TreeNode* q) {
  if (root == NULL) {
    return NULL;
  }

  if (root == q || root == p) {
    return root;
  }

  struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
  struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

  if (left != NULL && right != NULL) {
    return root;
  }
  if (left != NULL) {
    return left;
  }

  return right;
}
// @lc code=end
