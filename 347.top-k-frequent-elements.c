/*
 * @lc app=leetcode id=347 lang=c
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
  int val;
  int freq;
} HeapNode;

void swap(HeapNode* a, HeapNode* b) {
  HeapNode temp = *a;
  *a = *b;
  *b = temp;
}

void heapPush(HeapNode* heap, int* size, HeapNode node) {
  heap[*size] = node;
  int i = *size;
  (*size)++;

  while (i > 0) {
    int parent = (i - 1) / 2;

    if (heap[parent].freq <= heap[i].freq) {
      break;
    }

    swap(&heap[parent], &heap[i]);
    i = parent;
  }
}

void heapPop(HeapNode* heap, int* size) {
  heap[0] = heap[*size - 1];
  (*size)--;

  int i = 0;

  while (1) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < *size && heap[left].freq < heap[smallest].freq) {
      smallest = left;
    }

    if (right < *size && heap[right].freq < heap[smallest].freq) {
      smallest = right;
    }

    if (smallest == i) {
      break;
    }

    swap(&heap[i], &heap[smallest]);
    i = smallest;
  }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
  HeapNode* heap = malloc(k * sizeof(HeapNode));
  int heapSize = 0;
  int count[20001] = {0};

  for (int i = 0; i < numsSize; i++) {
    count[nums[i] + 10000]++;
  }

  for (int i = 0; i < 20001; i++) {
    if (count[i] > 0) {
      int val = i - 10000;
      int freq = count[i];

      HeapNode node;
      node.val = val;
      node.freq = freq;

      if (heapSize < k) {
        heapPush(heap, &heapSize, node);
      } else if (node.freq > heap[0].freq) {
        heapPop(heap, &heapSize);
        heapPush(heap, &heapSize, node);
      }
    }
  }

  int* result = malloc(k * sizeof(int));

  for (int i = 0; i < k; i++) {
    result[i] = heap[i].val;
  }

  *returnSize = k;

  free(heap);

  return result;
}
// @lc code=end
