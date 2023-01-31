/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode *root) {
  if (!root)
    return 0;
  if (!root->left && !root->right)
    return 1;
  if (!root->right)
    return 1 + minDepth(root->left);
  if (!root->left)
    return 1 + minDepth(root->right);

  int l = minDepth(root->left), r = minDepth(root->right);
  return 1 + (l < r ? l : r);
}
