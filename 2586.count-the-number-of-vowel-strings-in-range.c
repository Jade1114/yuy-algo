/*
 * @lc app=leetcode id=2586 lang=c
 *
 * [2586] Count the Number of Vowel Strings in Range
 */

// @lc code=start
#include <string.h>

int vowelStrings(char** words, int wordsSize, int left, int right) {
  int count = 0;

  for (int i = left; i <= right; i++) {
    char c = words[i][0];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      char e = words[i][strlen(words[i]) - 1];
      if (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u') {
        count++;
      }
    }
  }

  return count;
}
// @lc code=end
