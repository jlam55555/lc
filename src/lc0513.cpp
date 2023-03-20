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
  int findBottomLeftValue(TreeNode *root) {
    std::vector<TreeNode *> curr{root}, next;
    int res;

    // Level-order traversal.
    while (!curr.empty()) {
      // Get first element from this row.
      res = curr.front()->val;

      // Generate next row.
      for (auto *node : curr) {
        if (node->left) {
          next.push_back(node->left);
        }
        if (node->right) {
          next.push_back(node->right);
        }
      }
      std::swap(curr, next);
      next.clear();
    }
    return res;
  }
};
