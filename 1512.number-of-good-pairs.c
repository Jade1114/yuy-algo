/*
 * @lc app=leetcode id=1512 lang=c
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
int numIdenticalPairs(int* nums, int numsSize) {
  int pair_count = 0;
  for (size_t i = 0; i < numsSize; i++) {
    for (size_t j = i + 1; j < numsSize; j++) {
      if (nums[i] == nums[j]) {
        pair_count++;
      }
    }
  }

  return pair_count;
}
// @lc code=end
