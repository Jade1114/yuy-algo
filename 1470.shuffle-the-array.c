/*
 * @lc app=leetcode id=1470 lang=c
 *
 * [1470] Shuffle the Array
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
  *returnSize = numsSize;
  int* result = malloc(numsSize * sizeof(int));

  for (int i = 0; i < n; i++) {
    result[2 * i] = nums[i];
    result[2 * i + 1] = nums[i + n];
  }

  return result;
}
// @lc code=end
