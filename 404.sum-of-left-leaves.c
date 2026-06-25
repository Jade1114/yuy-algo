/*
 * @lc app=leetcode id=404 lang=c
 *
 * [404] Sum of Left Leaves
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

void dfs(struct TreeNode* curr, bool isLeft, int* sum) {
  if (curr == NULL) {
    return;
  }

  if (curr->left == NULL && curr->right == NULL) {
    if (isLeft) {
      *sum += curr->val;
    }
  }

  dfs(curr->left, true, sum);
  dfs(curr->right, false, sum);
}

int sumOfLeftLeaves(struct TreeNode* root) {
  int sum = 0;

  dfs(root, false, &sum);

  return sum;
}
// @lc code=end
