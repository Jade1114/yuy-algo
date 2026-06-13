/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct HashNode {
  int key;
  int value;
  struct HashNode* next;
} HashNode;

// 10007 是一个质数，哈希表长度用质数，通常能减少某些规律数据造成的集中冲突。
#define HASH_SIZE 10007

int hash(int key) {
  int index = key % HASH_SIZE;
  if (index < 0) {
    index += HASH_SIZE;
  }
  return index;
}

HashNode* find(HashNode** hashTable, int key) {
  int index = hash(key);
  HashNode* current = hashTable[index];
  while (current != NULL) {
    if (current->key == key) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void put(HashNode** hashTable, int key, int value) {
  int index = hash(key);
  HashNode* node = malloc(sizeof(HashNode));
  node->key = key;
  node->value = value;
  node->next = hashTable[index];
  hashTable[index] = node;
}

void freeHashTable(HashNode** hashTable) {
  for (int i = 0; i < HASH_SIZE; i++) {
    HashNode* current = hashTable[i];
    while (current != NULL) {
      HashNode* temp = current;
      current = current->next;
      free(temp);
    }
  }
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

  HashNode* hashTable[HASH_SIZE] = {0};

  *returnSize = 2;
  int* result = malloc(*returnSize * sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    int need = target - nums[i];
    HashNode* found = find(hashTable, need);
    if (found != NULL) {
      result[0] = found->value;
      result[1] = i;
      freeHashTable(hashTable);
      return result;
    }
    put(hashTable, nums[i], i);
  }

  freeHashTable(hashTable);
  free(result);
  *returnSize = 0;
  return NULL;
}
// @lc code=end
