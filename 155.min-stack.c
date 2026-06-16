/*
 * @lc app=leetcode id=155 lang=c
 *
 * [155] Min Stack
 */

// @lc code=start

typedef struct {
  int val[INT_MAX];
  int min[INT_MAX];
  int top;
} MinStack;

MinStack* minStackCreate() {
  MinStack* s = malloc(sizeof(MinStack));
  s->top = -1;
  return s;
}

void minStackPush(MinStack* obj, int value) {
  obj->top++;
  obj->val[obj->top] = value;
  if (obj->top == 0) {
    obj->min[obj->top] = value;
  } else {
    int prevMin = obj->min[obj->top - 1];
    obj->min[obj->top] = (value < prevMin) ? value : prevMin;
  }
}

void minStackPop(MinStack* obj) {
  obj->top--;
}

int minStackTop(MinStack* obj) {
  return obj->val[obj->top];
}

int minStackGetMin(MinStack* obj) {
  return obj->min[obj->top];
}

void minStackFree(MinStack* obj) {
  free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
// @lc code=end
