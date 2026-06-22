/*
 * @lc app=leetcode id=103 lang=c
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void reverse(int* arr, int size) {
  int left = 0;
  int right = size - 1;

  while (left < right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    left++;
    right--;
  }
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;

  if (root == NULL) {
    *returnColumnSizes = NULL;
    return NULL;
  }

  int** res = malloc(2000 * sizeof(int*));
  *returnColumnSizes = malloc(2000 * sizeof(int));

  struct TreeNode* queue[2000];
  int front = 0;
  int rear = 0;

  bool isReverse = false;

  queue[rear++] = root;

  while (front < rear) {
    int levelSize = rear - front;

    res[*returnSize] = malloc(levelSize * sizeof(int));
    (*returnColumnSizes)[*returnSize] = levelSize;

    for (int i = 0; i < levelSize; i++) {
      struct TreeNode* curr = queue[front++];

      res[*returnSize][i] = curr->val;

      if (curr->left != NULL) {
        queue[rear++] = curr->left;
      }

      if (curr->right != NULL) {
        queue[rear++] = curr->right;
      }
    }

    if (isReverse) {
      reverse(res[*returnSize], levelSize);
    }

    (*returnSize)++;
    isReverse = !isReverse;
  }

  return res;
}
// @lc code=end
