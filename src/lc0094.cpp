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
  void dfs(vector<int> &res, TreeNode *t) {
    if (!t)
      return;

    dfs(res, t->left);
    res.push_back(t->val);
    dfs(res, t->right);
  }

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res{};

    dfs(res, root);

    return res;
  }
};
