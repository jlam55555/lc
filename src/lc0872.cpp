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
  void Inorder(TreeNode *root, std::vector<int> &leaves) {
    if (!root) {
      return;
    }

    if (!root->left && !root->right) {
      leaves.push_back(root->val);
      return;
    }

    Inorder(root->left, leaves);
    Inorder(root->right, leaves);
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    // Inorder traversal, get leaves.
    std::vector<int> l1, l2;
    Inorder(root1, l1);
    Inorder(root2, l2);
    return l1 == l2;
  }
};
