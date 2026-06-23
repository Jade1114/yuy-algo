/*
 * @lc app=leetcode id=257 lang=c
 *
 * [257] Binary Tree Paths
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
void dfs(struct TreeNode* root, char* path, char** res, int* returnSize) {
  if (root == NULL) {
    return;
  }

  char newPath[1000];

  if (path[0] == '\0') {
    sprintf(newPath, "%d", root->val);
  } else {
    sprintf(newPath, "%s->%d", path, root->val);
  }

  if (root->left == NULL && root->right == NULL) {
    res[*returnSize] = malloc(strlen(newPath) + 1);
    strcpy(res[*returnSize], newPath);
    (*returnSize)++;
    return;
  }

  dfs(root->left, newPath, res, returnSize);
  dfs(root->right, newPath, res, returnSize);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
  char** res = malloc(1000 * sizeof(char*));
  *returnSize = 0;

  char path[1000] = "";

  dfs(root, path, res, returnSize);

  return res;
}
// @lc code=end
