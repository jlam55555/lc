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
      // Shouldn't be reached, except on tree root.
      return {INT_MAX, INT_MIN};
    }

    auto left{root->val}, right{root->val};
    if (root->right) {
      auto right_range{Dfs(root->right, res)};
      right = right_range.second;
      res = std::min(res, right_range.first - root->val);
    }
    if (root->left) {
      auto left_range{Dfs(root->left, res)};
      left = left_range.first;
      res = std::min(res, root->val - left_range.second);
    }
    return {left, right};
  }

  int getMinimumDifference(TreeNode *root) {
    int res{INT_MAX};
    Dfs(root, res);
    return res;
  }
};
