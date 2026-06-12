/*
 * @lc app=leetcode id=709 lang=c
 *
 * [709] To Lower Case
 */

// @lc code=start
char* toLowerCase(char* s) {

  for (int i = 0; s[i]; i++) {

    if (s[i] >= 'A' && s[i] <= 'Z') {

      s[i] += 32;
    }
  }

  return s;
}
// @lc code=end
