/*
 * @lc app=leetcode id=501 lang=c
 *
 * [501] Find Mode in Binary Search Tree
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* root, int* prevVal, bool* hasPrev, int* count, int* maxCount,
             int* result, int* returnSize) {
  if (root == NULL) {
    return;
  }

  inorder(root->left, prevVal, hasPrev, count, maxCount, result, returnSize);

  int val = root->val;

  if (!(*hasPrev)) {
    *count = 1;
    *hasPrev = true;
  } else if (val == *prevVal) {
    (*count)++;
  } else {
    *count = 1;
  }

  if (*count > *maxCount) {
    *maxCount = *count;
    *returnSize = 0;
    result[(*returnSize)++] = val;
  } else if (*count == *maxCount) {
    result[(*returnSize)++] = val;
  }

  *prevVal = val;

  inorder(root->right, prevVal, hasPrev, count, maxCount, result, returnSize);
}

int* findMode(struct TreeNode* root, int* returnSize) {
  int* result = malloc(sizeof(int) * 10000);

  int prevVal = 0;
  bool hasPrev = false;
  int count = 0;
  int maxCount = 0;

  *returnSize = 0;

  inorder(root, &prevVal, &hasPrev, &count, &maxCount, result, returnSize);

  return result;
}
// @lc code=end