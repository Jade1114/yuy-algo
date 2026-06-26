/*
 * @lc app=leetcode id=530 lang=c
 *
 * [530] Minimum Absolute Difference in BST
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

void inorder(struct TreeNode* root, struct TreeNode** prev, int* minDiff) {
  if (root == NULL) {
    return;
  }

  inorder(root->left, prev, minDiff);

  if (*prev != NULL) {
    int diff = root->val - (*prev)->val;
    if (diff < *minDiff) {
      *minDiff = diff;
    }
  }

  *prev = root;

  inorder(root->right, prev, minDiff);
}

int getMinimumDifference(struct TreeNode* root) {
  struct TreeNode* prev = NULL;
  int minDiff = INT_MAX;

  inorder(root, &prev, &minDiff);

  return minDiff;
}
// @lc code=end
