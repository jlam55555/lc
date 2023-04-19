// Standard tree recursion problem. Store the best
// result for the left and right, and the best
// result seen in this subtree.

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
  struct Result {
    int longest{};
    int left{};
    int right{};
  };

public:
  Result Dfs(TreeNode *root) {
    Result res;
    if (!root) {
      return res;
    }
    auto left{Dfs(root->left)}, right{Dfs(root->right)};
    res.left = 1 + left.right;
    res.right = 1 + right.left;
    res.longest = std::max({left.longest, right.longest, res.left, res.right});
    return res;
  }

  int longestZigZag(TreeNode *root) { return Dfs(root).longest - 1; }
};
