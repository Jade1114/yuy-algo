/*
 * @lc app=leetcode id=2469 lang=c
 *
 * [2469] Convert the Temperature
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
  *returnSize = 2;

  double* ans = (double*)malloc(2*sizeof(double));

  ans[0] = celsius + 273.15;
  ans[1] = celsius * 1.80 + 32.00;

  return ans;
}
// @lc code=end

