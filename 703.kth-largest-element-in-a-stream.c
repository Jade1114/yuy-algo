/*
 * @lc app=leetcode id=703 lang=c
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

typedef struct {
  int* heap;
  int size;
  int k;
} KthLargest;

void heapPush(int* heap, int* size, int val) {
  heap[*size] = val;
  int i = *size;
  (*size)++;

  while (i > 0) {
    int parent = (i - 1) / 2;

    if (heap[parent] <= heap[i]) {
      break;
    }

    swap(&heap[parent], &heap[i]);
    i = parent;
  }
}

void heapPop(int* heap, int* size) {
  heap[0] = heap[*size - 1];
  (*size)--;

  int i = 0;
  while (1) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < *size && heap[left] < heap[smallest]) {
      smallest = left;
    }

    if (right < *size && heap[right] < heap[smallest]) {
      smallest = right;
    }

    if (smallest == i) {
      break;
    }

    swap(&heap[i], &heap[smallest]);
    i = smallest;
  }
}

int kthLargestAdd(KthLargest* obj, int val) {
  if (obj->size < obj->k) {
    heapPush(obj->heap, &obj->size, val);
  } else if (val > obj->heap[0]) {
    heapPop(obj->heap, &obj->size);
    heapPush(obj->heap, &obj->size, val);
  }

  return obj->heap[0];
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
  KthLargest* obj = malloc(sizeof(KthLargest));

  obj->heap = malloc(k * sizeof(int));
  obj->size = 0;
  obj->k = k;

  for (int i = 0; i < numsSize; i++) {
    kthLargestAdd(obj, nums[i]);
  }
  return obj;
}

void kthLargestFree(KthLargest* obj) {
  free(obj->heap);
  free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/
// @lc code=end
