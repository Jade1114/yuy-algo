/*
 * @lc app=leetcode id=42 lang=c
 *
 * [42] Trapping Rain Water
 */

// @lc code=start

int trap(int* height, int heightSize) {
  if (heightSize < 3) {
    return 0;
  }

  int stack[20000];
  int top = -1;
  int sum = 0;

  for (int i = 0; i < heightSize; i++) {
    while (top != -1 && height[i] > height[stack[top]]) {
      int bottom = stack[top--];
      if (top == -1) {
        break;
      }
      int left = stack[top];
      int width = i - left - 1;
      int boundedHeight = (height[left] < height[i] ? height[left] : height[i]) - height[bottom];
      sum += width * boundedHeight;
    }

    stack[++top] = i;
  }

  return sum;
}
// @lc code=end
