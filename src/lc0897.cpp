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
  // Return top left, bottom right.
  std::pair<TreeNode *, TreeNode *> Rearrange(TreeNode *root) {
    if (!root) {
      return {nullptr, nullptr};
    }

    // Compute left and right ranges.
    auto left = Rearrange(root->left);
    auto right = Rearrange(root->right);

    // Do the rearranging.
    if (left.second)
      left.second->right = root;
    root->right = right.first;

    // Fix extra references.
    root->left = nullptr;
    if (right.second)
      right.second->right = nullptr;

    return {left.first ? left.first : root, right.second ? right.second : root};
  }

  TreeNode *increasingBST(TreeNode *root) { return Rearrange(root).first; }
};
