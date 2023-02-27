/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool evaluateTree(TreeNode *root) {
    if (root->val < 2) {
      return root->val;
    }

    // Don't precompute left and right so that we get the boolean
    // operator short-circuiting behavior.
    return root->val == 2
               ? evaluateTree(root->left) || evaluateTree(root->right)
               : evaluateTree(root->left) && evaluateTree(root->right);
  }
};
