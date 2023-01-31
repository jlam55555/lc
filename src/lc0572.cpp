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
  bool isEquiv(TreeNode *t1, TreeNode *t2) {
    if (!t1 && !t2) {
      return true;
    }

    if (!t1 || !t2) {
      return false;
    }

    return t1->val == t2->val && isEquiv(t1->left, t2->left) &&
           isEquiv(t1->right, t2->right);
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root && !subRoot) {
      return true;
    }

    if (!root || !subRoot) {
      return false;
    }

    return isEquiv(root, subRoot) || isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
  }
};
