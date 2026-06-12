/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 */

// @lc code=start
void moveZeroes(int* nums, int numsSize) {
  int slow = 0;
  int temp = 0;
  for (int fast = 1; fast < numsSize; fast++) {

    if (nums[slow] != 0) {
      slow++;
    } else {
      if (nums[fast] != 0) {
        temp = nums[slow];
        nums[slow] = nums[fast];
        nums[fast] = temp;

        slow++;
      }
    }
  }
}
// @lc code=end
