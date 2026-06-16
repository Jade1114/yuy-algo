/*
 * @lc app=leetcode id=739 lang=c
 *
 * [739] Daily Temperatures
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
  *returnSize = temperaturesSize;
  int* forcast = malloc(temperaturesSize * sizeof(int));

  int* stack = malloc(temperaturesSize * sizeof(int));
  int top = -1;

  for (int i = 0; i < temperaturesSize; i++) {
    forcast[i] = 0;
  }

  for (int i = 0; i < temperaturesSize; i++) {
    if (top == -1 || temperatures[stack[top]] > temperatures[i]) {
      stack[++top] = i;
    } else {
      while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
        int idx = stack[top--];
        forcast[idx] = i - idx;
      }
      stack[++top] = i;
    }
  }

  free(stack);
  return forcast;
}
// @lc code=end
