/*
 * @lc app=leetcode id=2413 lang=c
 *
 * [2413] Smallest Even Multiple
 */

// @lc code=start
int smallestEvenMultiple(int n) {
  return (n & 1) ? n*2 : n;
}
// @lc code=end

