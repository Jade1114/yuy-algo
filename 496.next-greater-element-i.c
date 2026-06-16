/*
 * @lc app=leetcode id=496 lang=c
 *
 * [496] Next Greater Element I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  *returnSize = nums1Size;
  int* res = malloc(nums1Size * sizeof(int));
  int stack[1000];
  int top = -1;
  // map[x] = 右边第一个比 x 大的数，默认 -1
  int map[10001];
  for (int i = 0; i <= 10000; i++) {
    map[i] = -1;
  }
  // ========== 核心：从左往右扫 nums2，单调递减栈 ==========
  for (int i = 0; i < nums2Size; i++) {
    int cur = nums2[i];
    // cur 比栈顶元素大 → 栈顶元素都找到答案了
    while (top != -1 && cur > stack[top]) {
      map[stack[top]] = cur; // 🔴 弹掉时记录答案
      top--;
    }
    // cur 入栈（等着后面更大的数来弹它）
    stack[++top] = cur;
  }
  // 栈里剩下的 → map 里还是默认的 -1，不用处理
  // ========== 查表输出 ==========
  for (int i = 0; i < nums1Size; i++) {
    res[i] = map[nums1[i]];
  }
  return res;
}
// @lc code=end
