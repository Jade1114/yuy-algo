/*
 * @lc app=leetcode id=704 lang=c
 *
 * [704] Binary Search
 */

// @lc code=start
int search(int* nums, int numsSize, int target) {

  int left = 0;
  int right = numsSize - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}
// @lc code=end
