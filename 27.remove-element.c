/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start
int removeElement(int* nums, int numsSize, int val) {
  int slow = 0;
  for (int fast = 0; fast < numsSize; fast++) {
    if (nums[fast] != val) {
      nums[slow] = nums[fast];
      slow++;
    }
  }
  return slow;
}
// @lc code=end
