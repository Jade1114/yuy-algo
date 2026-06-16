/*
 * @lc app=leetcode id=232 lang=c
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start

typedef struct {
  int stackIn[10000];
  int stackOut[10000];
  int topIn;
  int topOut;
} MyQueue;

MyQueue* myQueueCreate() {
  MyQueue* mq = malloc(sizeof(MyQueue));
  mq->topIn = -1;
  mq->topOut = -1;
  return mq;
}

void myQueuePush(MyQueue* obj, int x) {
  obj->stackIn[++obj->topIn] = x;
}

int myQueuePop(MyQueue* obj) {
  if (obj->topOut == -1) {
    while (obj->topIn != -1) {
      obj->stackOut[++obj->topOut] = obj->stackIn[obj->topIn--];
    }
  }
  return obj->stackOut[obj->topOut--];
}

int myQueuePeek(MyQueue* obj) {
  if (obj->topOut == -1) {
    while (obj->topIn != -1) {
      obj->stackOut[++obj->topOut] = obj->stackIn[obj->topIn--];
    }
  }
  return obj->stackOut[obj->topOut];
}

bool myQueueEmpty(MyQueue* obj) {
  return obj->topIn == -1 && obj->topOut == -1;
}

void myQueueFree(MyQueue* obj) {
  free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
// @lc code=end
