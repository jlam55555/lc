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

// I use a pretty straightforward method here by checking the minimum and
// maximum depths of the left and right subtrees. The editorial's solution of
// using an array representation of the complete tree is pretty interesting.
class Solution {
public:
  // Returns the maximum and minimum depth of the tree if it is complete,
  // otherwise std::nullopt.
  std::optional<std::pair<int, int>> GetDepthOfCompleteTree(TreeNode *root) {
    if (!root) {
      return {{0, 0}};
    }

    auto depth_left{GetDepthOfCompleteTree(root->left)},
        depth_right{GetDepthOfCompleteTree(root->right)};
    if (depth_left && depth_right) {
      auto [left_max, left_min] = *depth_left;
      auto [right_max, right_min] = *depth_right;
      if (left_max >= right_min && left_max - right_min <= 1 &&
          left_min >= right_max) {
        return {{left_max + 1, right_min + 1}};
      }
    }
    return {};
  }

  // Check if each node on the left and right have the same depth.
  // We use the explicit conversion operator from std::optional<T>
  // to bool.
  bool isCompleteTree(TreeNode *root) {
    return static_cast<bool>(GetDepthOfCompleteTree(root));
  }
};
