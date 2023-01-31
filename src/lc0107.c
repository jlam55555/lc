/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **levelOrderBottom(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes) {
  if (!root) {
    *returnSize = 0;
    return NULL;
  }

  int **retValue, queueLength = 1, i = 0, j, nextEndDepth = 0,
                  prevEndDepth = -1, maxDepth = 5000, maxQueueSize = 5000;
  struct TreeNode *queue[maxQueueSize], *curTree;

  *returnColumnSizes = (int *)malloc(maxDepth * sizeof(int *));
  retValue = (int **)malloc(maxDepth * sizeof(int *));
  *returnSize = 0;
  memset(queue, '\0', 100 * sizeof(struct TreeNode *));

  queue[0] = curTree = root;
  while (curTree) {
    if (curTree->left)
      queue[queueLength++] = curTree->left;
    if (curTree->right)
      queue[queueLength++] = curTree->right;
    if (i++ == nextEndDepth) {
      (*returnColumnSizes)[maxDepth - 1 - *returnSize] =
          nextEndDepth - prevEndDepth;
      retValue[maxDepth - 1 - *returnSize] =
          (int *)malloc((nextEndDepth - prevEndDepth) * sizeof(int));
      for (j = 0; j < nextEndDepth - prevEndDepth; j++) {
        retValue[maxDepth - 1 - *returnSize][j] =
            queue[prevEndDepth + 1 + j]->val;
      }
      *returnSize += 1;
      prevEndDepth = nextEndDepth;
      nextEndDepth = queueLength - 1;
    }
    curTree = queue[i];
  }

  *returnColumnSizes = *returnColumnSizes + (maxDepth - *returnSize);
  retValue = retValue + (maxDepth - *returnSize);

  return retValue;
}
