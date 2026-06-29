/*
 * @lc app=leetcode id=230 lang=c
 *
 * [230] Kth Smallest Element in a BST
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
void inorder(struct TreeNode* root, int k, int* count, int* answer) {
  if (root == NULL) {
    return;
  }

  if (*count >= k) {
    return;
  }

  inorder(root->left, k, count, answer);

  if (*count >= k) {
    return;
  }

  (*count)++;

  if (*count == k) {
    *answer = root->val;
    return;
  }

  inorder(root->right, k, count, answer);
}

int kthSmallest(struct TreeNode* root, int k) {
  int count = 0;
  int answer = 0;

  inorder(root, k, &count, &answer);

  return answer;
}

// @lc code=end
