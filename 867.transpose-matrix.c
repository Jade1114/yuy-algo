/*
 * @lc app=leetcode id=867 lang=c
 *
 * [867] Transpose Matrix
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize,
                int** returnColumnSizes) {
  int rows = matrixSize;
  int cols = matrixColSize;
  *returnSize = cols;
  *returnColumnSizes = malloc(cols * sizeof(int));

  for (int i = 0; i < cols; i++) {
    (*returnColumnSizes)[i] = rows;
  }

  int** result = malloc(cols * sizeof(int*));

  for (int i = 0; i < cols; i++) {

    result[i] = malloc(rows * sizeof(int));
  }

  for (int i = 0; i < rows; i++) {

    for (int j = 0; j < cols; j++) {

      result[j][i] = matrix[i][j];
    }
  }
}
// @lc code=end
