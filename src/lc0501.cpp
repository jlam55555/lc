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
  void Dfs(TreeNode *root, std::unordered_map<int, int> &vals) {
    if (!root) {
      return;
    }

    ++vals[root->val];
    Dfs(root->left, vals);
    Dfs(root->right, vals);
  }

  vector<int> findMode(TreeNode *root) {
    std::vector<int> res{};
    std::unordered_map<int, int> vals{};
    Dfs(root, vals);
    auto max_val{INT_MIN};
    for (const auto &entry : vals) {
      max_val = std::max(max_val, entry.second);
    }
    for (const auto &entry : vals) {
      if (entry.second == max_val) {
        res.push_back(entry.first);
      }
    }
    return res;
  }
};
