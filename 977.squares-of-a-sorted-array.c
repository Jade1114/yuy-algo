/*
 * @lc app=leetcode id=977 lang=c
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int* result = malloc(*returnSize * sizeof(int));

  int left = 0;
  int right = numsSize - 1;
  int pos = numsSize - 1;

  while (left <= right) {

    int leftSquare = nums[left] * nums[left];

    int rightSquare = nums[right] * nums[right];

    if (leftSquare > rightSquare) {

      result[pos] = leftSquare;

      left++;

    } else {

      result[pos] = rightSquare;

      right--;
    }

    pos--;
  }

  return result;
}
// @lc code=end
