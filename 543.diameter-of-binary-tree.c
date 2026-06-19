/*
 * @lc app=leetcode id=543 lang=c
 *
 * [543] Diameter of Binary Tree
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
int diameter = 0;
int dfs(struct TreeNode* root) {
  if (root == NULL) {
    return 0;
  }

  int left = dfs(root->left);
  int right = dfs(root->right);

  diameter = fmax(diameter, left + right);

  return fmax(left, right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
  diameter = 0;
  dfs(root);
  return diameter;
}
// @lc code=end
