/*
 * @lc app=leetcode id=973 lang=c
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct {
  int x;
  int y;
  int dist;
} PointNode;

void swap(PointNode* a, PointNode* b) {
  PointNode temp = *b;
  *b = *a;
  *a = temp;
}

void heapPush(PointNode* heap, int* size, PointNode node) {
  int i = *size;
  heap[i] = node;
  (*size)++;

  while (i > 0) {
    int parent = (i - 1) / 2;

    if (heap[parent].dist >= heap[i].dist) {
      break;
    }

    swap(&heap[parent], &heap[i]);
    i = parent;
  }
}

void heapPop(PointNode* heap, int* size) {
  heap[0] = heap[*size - 1];
  (*size)--;

  int i = 0;
  while (1) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < *size && heap[left].dist > heap[largest].dist) {
      largest = left;
    }

    if (right < *size && heap[right].dist > heap[largest].dist) {
      largest = right;
    }

    if (largest == i) {
      break;
    }

    swap(&heap[i], &heap[largest]);
    i = largest;
  }
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize,
               int** returnColumnSizes) {

  PointNode* heap = malloc(k * sizeof(PointNode));
  int heapSize = 0;

  for (int i = 0; i < pointsSize; i++) {

    int x = points[i][0];
    int y = points[i][1];
    int dist = x * x + y * y;

    PointNode node = {x, y, dist};

    if (heapSize < k) {
      heapPush(heap, &heapSize, node);
    } else if (node.dist < heap[0].dist) {
      heapPop(heap, &heapSize);
      heapPush(heap, &heapSize, node);
    }
  }

  *returnSize = k;
  *returnColumnSizes = malloc(k * sizeof(int));

  int** result = malloc(k * sizeof(int*));

  for (int i = 0; i < k; i++) {
    result[i] = malloc(2 * sizeof(int));
    result[i][0] = heap[i].x;
    result[i][1] = heap[i].y;
    (*returnColumnSizes)[i] = 2;
  }

  free(heap);
  return result;
}
// @lc code=end
