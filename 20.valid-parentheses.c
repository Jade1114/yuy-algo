/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */

// @lc code=start
bool isValid(char* s) {
  int stack[10000];
  int top = -1;
  for (char* p = s; *p; p++) {
    if (*p == '(' || *p == '[' || *p == '{') {
      stack[++top] = *p;
    } else {
      if (top == -1)
        return false; // 栈空，没有可匹配的左括号
      char left = stack[top--];
      if ((*p == ')' && left != '(') || (*p == ']' && left != '[') || (*p == '}' && left != '{')) {
        return false;
      }
    }
  }
  return top == -1;
}
// @lc code=end
