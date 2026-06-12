/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */

// @lc code=start
int searchInsert(int* nums, int numsSize, int target) {
  int left = 0;
  int right = numsSize - 1;
  int mid = 0;
  int index = 0;

  while (left <= right) {
    mid = left + (right - left) / 2;
    if (nums[mid] == target)
      return mid;
    if (nums[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return left;
}
// @lc code=end
