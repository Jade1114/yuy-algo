/*
 * @lc app=leetcode id=503 lang=c
 *
 * [503] Next Greater Element II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
  int* ans = malloc(numsSize * sizeof(int));
  int* stack = malloc(numsSize * sizeof(int));
  int top = -1;
  *returnSize = numsSize;

  for (int i = 0; i < numsSize; i++) {
    ans[i] = -1;
  }

  for (int i = 0; i < 2 * numsSize; i++) {
    int idx = i % numsSize;
    while (top != -1 && nums[idx] > nums[stack[top]]) {
      ans[stack[top]] = nums[idx];
      top--;
    }
    if (i < numsSize) {
      stack[++top] = idx;
    }
  }

  free(stack);
  return ans;
}
// @lc code=end
