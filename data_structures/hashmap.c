typedef struct HashNode {
  int key;
  int value;
  struct HashNode* next;
} HashNode;

// 10007 是一个质数，哈希表长度用质数，通常能减少某些规律数据造成的集中冲突。
#define HASH_SIZE 10007

HashNode* hashTable[HASH_SIZE] = {0};

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