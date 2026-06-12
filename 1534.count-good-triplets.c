/*
 * @lc app=leetcode id=1534 lang=c
 *
 * [1534] Count Good Triplets
 */

// @lc code=start

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
  int count = 0;
  for (size_t i = 0; i < arrSize; i++) {
    for (size_t j = i + 1; j < arrSize; j++) {
      if (abs(arr[i] - arr[j]) <= a) {
        for (size_t k = j + 1; k < arrSize; k++) {
          if (abs(arr[j] - arr[k]) <= b) {
            if (abs(arr[i] - arr[k]) <= c) {
              count++;
            }
          }
        }
      }
    }
  }

  /*
      for (int i = 0; i < arrSize; i++) {

        for (int j = i + 1; j < arrSize; j++) {

            for (int k = j + 1; k < arrSize; k++) {

                if (abs(arr[i] - arr[j]) <= a &&

                    abs(arr[j] - arr[k]) <= b &&

                    abs(arr[i] - arr[k]) <= c) {

                    count++;

                }

            }

        }

    }*/

  return count;
}
// @lc code=end
