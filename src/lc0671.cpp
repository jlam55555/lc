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
  void Dfs(TreeNode *root, long &res) {
    if (!root || !root->left) {
      return;
    }
    if (root->left->val != root->right->val) {
      res = std::min(res, long(std::max(root->left->val, root->right->val)));
    }
    Dfs(root->left, res);
    Dfs(root->right, res);
  }

  int findSecondMinimumValue(TreeNode *root) {
    long res{long(INT_MAX) + 1};
    Dfs(root, res);
    return res == long(INT_MAX) + 1 ? -1 : res;
  }
};
