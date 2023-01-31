/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  struct Result {
    bool found_p{};
    bool found_q{};
    TreeNode *solution{};
  };

public:
  Result dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return {false, false, nullptr};
    }
    bool found_p{root == p}, found_q{root == q};
    auto left = dfs(root->left, p, q);
    if (left.solution) {
      return left;
    }
    auto right = dfs(root->right, p, q);
    if (right.solution) {
      return right;
    }
    Result r{
        found_p || left.found_p || right.found_p,
        found_q || left.found_q || right.found_q,
    };
    if (r.found_p && r.found_q) {
      r.solution = root;
    }
    return r;
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return dfs(root, p, q).solution;
  }
};
