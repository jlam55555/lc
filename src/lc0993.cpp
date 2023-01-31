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
  int Dfs(TreeNode *root, int target, TreeNode *&parent) {
    if (!root) {
      return -1;
    }
    if (root->val == target) {
      return 0;
    }

    auto rval{-1};
    if (auto d{Dfs(root->left, target, parent)}; d != -1) {
      rval = d + 1;
    } else if (auto d{Dfs(root->right, target, parent)}; d != -1) {
      rval = d + 1;
    }
    if (rval == 1) {
      parent = root;
    }
    return rval;
  }

  bool isCousins(TreeNode *root, int x, int y) {
    TreeNode *p1, *p2;
    auto d1{Dfs(root, x, p1)};
    auto d2{Dfs(root, y, p2)};
    return d1 == d2 && p1 != p2;
  }
};
