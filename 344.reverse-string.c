/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */

// @lc code=start
void reverseString(char* s, int sSize) {
  int left = 0;
  int right = sSize - 1;

  while (left < right) {
    char temp;
    temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    left++;
    right--;
  }
}
// @lc code=end
