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
  void Dfs(TreeNode *root, std::string &res) {
    if (!root) {
      // Left node.
      return;
    }

    res += std::to_string(root->val);

    if (root->left || root->right) {
      res.push_back('(');
      Dfs(root->left, res);
      res.push_back(')');
    }
    if (root->right) {
      res.push_back('(');
      Dfs(root->right, res);
      res.push_back(')');
    }
  }

  string tree2str(TreeNode *root) {
    // Root guaranteed to be non-null.
    std::string res;
    Dfs(root, res);
    return res;
  }
};
