/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int EUNB = -2;

int getHeight(struct TreeNode *root) {
  if (!root)
    return -1;
  if (!root->left && !root->right)
    return 0;

  int leftHeight = getHeight(root->left), rightHeight = getHeight(root->right);

  if (leftHeight == EUNB || rightHeight == EUNB ||
      abs(leftHeight - rightHeight) > 1)
    return EUNB;
  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct TreeNode *root) { return getHeight(root) != EUNB; }
