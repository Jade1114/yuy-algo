/*
 * @lc app=leetcode id=258 lang=c
 *
 * [258] Add Digits
 */

// @lc code=start
int addDigits(int num) {
  return num == 0 ? 0 : 1 + (num - 1) % 9;
}
// @lc code=end
