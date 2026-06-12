/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
int removeDuplicates(int* nums, int numsSize) {

  if (numsSize == 0)
    return 0;
  int slow = 0;
  for (int fast = 1; fast < numsSize; fast++) {
    if (nums[slow] != nums[fast]) {
      slow++;
      nums[slow] = nums[fast];
    }
  }
  return slow + 1;
}
// @lc code=end
