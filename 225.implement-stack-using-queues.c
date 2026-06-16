/*
 * @lc app=leetcode id=225 lang=c
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start

// 用两个队列实现栈
// q1 存数据，q2 当搬运工
// push: 直接进 q1 队尾
// pop: 把 q1 前 n-1 个搬到 q2，弹 q1 最后一个，然后 q1/q2 互换

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void queueInit(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void queuePush(Queue* q, int x) {
    q->data[q->rear++] = x;
}

int queuePop(Queue* q) {
    return q->data[q->front++];
}

int queuePeek(Queue* q) {
    return q->data[q->front];
}

bool queueEmpty(Queue* q) {
    return q->front == q->rear;
}

int queueSize(Queue* q) {
    return q->rear - q->front;
}

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* s = malloc(sizeof(MyStack));
    queueInit(&s->q1);
    queueInit(&s->q2);
    return s;
}

void myStackPush(MyStack* obj, int x) {
    queuePush(&obj->q1, x);
}

int myStackPop(MyStack* obj) {
    // 把 q1 前 n-1 个搬到 q2，留下最后一个
    int size = queueSize(&obj->q1);
    for (int i = 0; i < size - 1; i++) {
        queuePush(&obj->q2, queuePop(&obj->q1));
    }
    // 弹掉 q1 最后一个 = 栈顶
    int val = queuePop(&obj->q1);

    // q1 q2 互换：q2 变成新的 q1
    Queue tmp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = tmp;

    return val;
}

int myStackTop(MyStack* obj) {
    // 跟 pop 一样，但最后一个元素放回 q2 而不是弹掉
    int size = queueSize(&obj->q1);
    for (int i = 0; i < size - 1; i++) {
        queuePush(&obj->q2, queuePop(&obj->q1));
    }
    int val = queuePop(&obj->q1);    // 取出栈顶
    queuePush(&obj->q2, val);        // 再放回去

    Queue tmp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = tmp;

    return val;
}

bool myStackEmpty(MyStack* obj) {
    return queueEmpty(&obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}

// @lc code=end
