/*
 * @lc app=leetcode id=23 lang=c
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void swap(struct ListNode** a, struct ListNode** b) {
  struct ListNode* temp = *a;
  *a = *b;
  *b = temp;
}

void heapPush(struct ListNode** heap, int* size, struct ListNode* node) {
  int i = *size;
  heap[i] = node;
  (*size)++;

  while (i > 0) {
    int parent = (i - 1) / 2;

    if (heap[parent]->val <= heap[i]->val) {
      break;
    }

    swap(&heap[parent], &heap[i]);
    i = parent;
  }
}

struct ListNode* heapPop(struct ListNode** heap, int* size) {
  struct ListNode* minNode = heap[0];
  heap[0] = heap[*size - 1];
  (*size)--;

  int i = 0;

  while (1) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < *size && heap[left]->val < heap[smallest]->val) {
      smallest = left;
    }

    if (right < *size && heap[right]->val < heap[smallest]->val) {
      smallest = right;
    }

    if (smallest == i) {
      break;
    }

    swap(&heap[i], &heap[smallest]);
    i = smallest;
  }

  return minNode;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
  if (listsSize == 0) {
    return NULL;
  }

  struct ListNode** heap = malloc(listsSize * sizeof(struct ListNode*));
  int heapSize = 0;

  for (int i = 0; i < listsSize; i++) {
    if (lists[i] != NULL) {
      heapPush(heap, &heapSize, lists[i]);
    }
  }

  struct ListNode dummy;
  dummy.next = NULL;
  struct ListNode* tail = &dummy;

  while (heapSize > 0) {
    struct ListNode* node = heapPop(heap, &heapSize);

    tail->next = node;
    tail = tail->next;

    if (node->next != NULL) {
      heapPush(heap, &heapSize, node->next);
    }
  }

  free(heap);

  return dummy.next;
}
// @lc code=end
