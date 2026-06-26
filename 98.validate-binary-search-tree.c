/*
 * @lc app=leetcode id=98 lang=c
 *
 * [98] Validate Binary Search Tree
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

bool inorder(struct TreeNode* root, long* prev, bool* hasPrev) {
  if (root == NULL) {
    return true;
  }

  if (!inorder(root->left, prev, hasPrev)) {
    return false;
  }

  if (*hasPrev && root->val <= *prev) {
    return false;
  }

  *prev = root->val;
  *hasPrev = true;

  return inorder(root->right, prev, hasPrev);
}

bool isValidBST(struct TreeNode* root) {
  long prev = 0;
  bool hasPrev = false;

  return inorder(root, &prev, &hasPrev);
}
// @lc code=end
