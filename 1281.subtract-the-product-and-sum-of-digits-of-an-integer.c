/*
 * @lc app=leetcode id=1281 lang=c
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
 */

// @lc code=start
int subtractProductAndSum(int n) {
  int product = 1;
  int sum = 0;

  while (n > 0) {

    int digit = n % 10;

    product *= digit;

    sum += digit;

    n /= 10;
  }

  return product - sum;
}
// @lc code=end
