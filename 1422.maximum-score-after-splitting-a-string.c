/*
 * @lc app=leetcode id=1422 lang=c
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
int maxScore(char* s) {
  int n = strlen(s);

  int ones = 0;

  for (int i = 0; i < n; i++) {

    if (s[i] == '1')

      ones++;
  }

  int zeros = 0;

  int maxScore = 0;

  for (int i = 0; i < n - 1; i++) {

    if (s[i] == '0')

      zeros++;

    else

      ones--; // 当前1移到左边，右边少一个1

    int score = zeros + ones;

    if (score > maxScore)

      maxScore = score;
  }

  return maxScore;
}
// @lc code=end
