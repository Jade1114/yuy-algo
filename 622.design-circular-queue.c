/*
 * @lc app=leetcode id=622 lang=c
 *
 * [622] Design Circular Queue
 */

// @lc code=start

typedef struct {
  int* data;
  int front;
  int rear;
  int capacity;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
  MyCircularQueue* q = malloc(sizeof(MyCircularQueue));
  q->data = malloc((k + 1) * sizeof(int)); // 多一个格子
  q->front = 0;
  q->rear = 0;
  q->capacity = k + 1;
  return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  if ((obj->rear + 1) % obj->capacity == obj->front)
    return false;
  obj->data[obj->rear] = value;
  obj->rear = (obj->rear + 1) % obj->capacity;
  return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  if (obj->front == obj->rear) {
    return false;
  }
  obj->front = (obj->front + 1) % obj->capacity;
  return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
  if (obj->front == obj->rear)
    return -1;
  return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
  if (obj->front == obj->rear)
    return -1;
  return obj->data[(obj->rear - 1 + obj->capacity) % obj->capacity];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return (obj->rear + 1) % obj->capacity == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
  free(obj->data);
  free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
// @lc code=end
