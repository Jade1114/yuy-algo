/*
 * @lc app=leetcode id=933 lang=c
 *
 * [933] Number of Recent Calls
 */

// @lc code=start

typedef struct {
  int* data;
  int front;
  int rear;
  int capacity;
} RecentCounter;

RecentCounter* recentCounterCreate() {
  RecentCounter* rc = malloc(sizeof(RecentCounter));
  rc->data = malloc(10001 * sizeof(int));
  rc->front = 0;
  rc->rear = 0;
  rc->capacity = 10001;

  return rc;
}

int recentCounterPing(RecentCounter* obj, int t) {
  obj->data[obj->rear] = t;
  obj->rear = (obj->rear + 1) % obj->capacity;

  while (obj->front != obj->rear && obj->data[obj->front] < t - 3000) {
    obj->front = (obj->front + 1) % obj->capacity;
  }

  return (obj->rear - obj->front + obj->capacity) % obj->capacity;
}

void recentCounterFree(RecentCounter* obj) {
  free(obj->data);
  free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/
// @lc code=end
