/*
 * @lc app=leetcode id=111 lang=c
 *
 * [111] Minimum Depth of Binary Tree
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
int minDepth(struct TreeNode* root) {
  if (root == NULL) {
    return 0;
  }

  struct TreeNode* queue[100000];
  int front = 0;
  int rear = 0;

  queue[rear++] = root;
  int minDepth = 1;

  while (front < rear) {
    int levelSize = rear - front;

    for (int i = 0; i < levelSize; i++) {
      struct TreeNode* curr = queue[front++];
      if (curr->left == NULL && curr->right == NULL) {
        return minDepth;
      }
      if (curr->left != NULL)
        queue[rear++] = curr->left;
      if (curr->right != NULL)
        queue[rear++] = curr->right;
    }
    minDepth++;
  }

  return minDepth;
}

// @lc code=end
