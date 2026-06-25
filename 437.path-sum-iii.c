/*
 * @lc app=leetcode id=437 lang=c
 *
 * [437] Path Sum III
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

int countFromNode(struct TreeNode* root, long target) {
  if (root == NULL) {
    return 0;
  }

  int count = 0;

  target -= root->val;

  if (target == 0) {
    count++;
  }

  count += countFromNode(root->left, target);
  count += countFromNode(root->right, target);

  return count;
}

/**
 * 确保能以每一个节点都进行父节点进行检查。
 */

int pathSum(struct TreeNode* root, int targetSum) {
  if (root == NULL) {
    return 0;
  }

  return countFromNode(root, targetSum) + pathSum(root->left, targetSum) +
         pathSum(root->right, targetSum);
}
// @lc code=end
