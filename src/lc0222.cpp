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
  bool hasElem(TreeNode *root, int depth, int m) {
    for (unsigned bit{1u << (depth - 1)}; bit; bit >>= 1) {
      root = m & bit ? root->right : root->left;
    }
    return !!root;
  }

  int countNodes(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int depth{};
    auto it{root};
    while (it) {
      it = it->right;
      ++depth;
    }

    // Bottom row has between 0 and 2^depth elements. Do a binary search.
    int l{}, r{(1 << depth) - 1};
    while (l < r) {
      auto m{(l + r) >> 1};
      if (hasElem(root, depth, m)) {
        l = m + 1;
      } else {
        r = m;
      }
    }

    return ((1 << depth) - 1) + l;
  }
};
