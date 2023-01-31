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
  std::vector<TreeNode *> helper(int l, int r) {
    if (r < l) {
      return {nullptr};
    }

    std::vector<TreeNode *> res;
    for (auto i{l}; i <= r; ++i) {
      auto left = helper(l, i - 1), right = helper(i + 1, r);
      for (auto j : left) {
        for (auto k : right) {
          res.push_back(new TreeNode(i, j, k));
        }
      }
    }
    return res;
  }

  vector<TreeNode *> generateTrees(int n) { return helper(1, n); }
};
