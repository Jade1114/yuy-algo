
int rear = 0;
int front = 0;

queue[rear++] = root;

while (front < rear) {

  // 当前层节点数
  int levelSize = rear - front;

  // ===== 每层初始化 =====

  for (int i = 0; i < levelSize; i++) {

    struct TreeNode* curr = queue[front++];

    // ===== 处理当前节点 =====

    if (curr->left != NULL) {
      queue[rear++] = curr->left;
    }

    if (curr->right != NULL) {
      queue[rear++] = curr->right;
    }
  }

  // ===== 每层结束处理 =====
}