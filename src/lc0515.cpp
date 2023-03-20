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
  // Level-order traversal, very similar to lc0513.cpp.
  vector<int> largestValues(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<TreeNode *> curr{root}, next;
    std::vector<int> res;

    // Level-order traversal.
    while (!curr.empty()) {
      int row_max{INT_MIN};
      // Generate next row.
      for (auto *node : curr) {
        row_max = std::max(row_max, node->val);
        if (node->left) {
          next.push_back(node->left);
        }
        if (node->right) {
          next.push_back(node->right);
        }
      }
      std::swap(curr, next);
      next.clear();
      res.push_back(row_max);
    }
    return res;
  }
};
