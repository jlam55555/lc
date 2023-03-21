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
  int maxAncestorDiff(TreeNode *root, int ancestor_min, int ancestor_max) {
    if (!root) {
      return 0;
    }
    return std::max({
        std::abs(root->val - ancestor_min),
        std::abs(root->val - ancestor_max),
        maxAncestorDiff(root->left, std::min(root->val, ancestor_min),
                        std::max(root->val, ancestor_max)),
        maxAncestorDiff(root->right, std::min(root->val, ancestor_min),
                        std::max(root->val, ancestor_max)),
    });
  }

  int maxAncestorDiff(TreeNode *root) {
    return maxAncestorDiff(root, root->val, root->val);
  }
};
