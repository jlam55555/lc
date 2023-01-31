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
  std::pair<int, int> Dfs(TreeNode *root, int &res) {
    if (!root) {
      // Shouldn't happen.
      return {INT_MAX, INT_MIN};
    }

    auto left_min{root->val};
    auto right_max{root->val};
    if (root->left) {
      auto rval{Dfs(root->left, res)};
      left_min = rval.first;
      res = std::min(res, root->val - rval.second);
    }
    if (root->right) {
      auto rval{Dfs(root->right, res)};
      right_max = rval.second;
      res = std::min(res, rval.first - root->val);
    }
    return {left_min, right_max};
  }

  int minDiffInBST(TreeNode *root) {
    auto res{INT_MAX};
    Dfs(root, res);
    return res;
  }
};
