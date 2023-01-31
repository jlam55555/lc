/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirrored(struct TreeNode *a, struct TreeNode *b) {
  return !(a || b) || a && b && a->val == b->val &&
                          isMirrored(a->left, b->right) &&
                          isMirrored(a->right, b->left);
}

bool isSymmetric(struct TreeNode *root) {
  return !root || isMirrored(root->left, root->right);
}
