/*
 * @lc app=leetcode id=852 lang=c
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
int peakIndexInMountainArray(int* arr, int arrSize) {
  int left = 0;

  int right = arrSize - 1;

  while (left < right) {

    int mid = left + (right - left) / 2;

    if (arr[mid] < arr[mid + 1]) {

      left = mid + 1;

    } else {

      right = mid;
    }
  }

  return left;
}
// @lc code=end
