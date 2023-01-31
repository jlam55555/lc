/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode *root, int sum) {
  if (!root)
    return false;
  if (!root->left && !root->right)
    return sum == root->val;
  if (!root->left)
    return hasPathSum(root->right, sum - root->val);
  if (!root->right)
    return hasPathSum(root->left, sum - root->val);

  return hasPathSum(root->left, sum - root->val) ||
         hasPathSum(root->right, sum - root->val);
}
