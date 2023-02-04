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

// Intuition: for each node, keep track of the maximum score
// including the root node and not including the root node.
class Solution {
public:
  // First value returned is including the root.
  // Second value returned is not including the root.
  std::pair<int, int> Dfs(TreeNode *root) {
    if (!root) {
      return {};
    }

    auto best_with_root{root->val};
    int best_wo_root{};

    if (root->left) {
      auto left = Dfs(root->left);
      best_with_root += left.second;
      best_wo_root += left.first;
    }

    if (root->right) {
      auto right = Dfs(root->right);
      best_with_root += right.second;
      best_wo_root += right.first;
    }

    return {std::max(best_with_root, best_wo_root), best_wo_root};
  }

  int rob(TreeNode *root) {
    return std::max(Dfs(root).first, Dfs(root).second);
  }
};
