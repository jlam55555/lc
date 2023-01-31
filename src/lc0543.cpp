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
  int Max(const std::vector<int> &p) { return std::max(p[0], p[2]); }

  std::vector<int> Diameter(TreeNode *root) {
    if (!root) {
      return {0, 0, 0};
    }
    auto d_left{Diameter(root->left)}, d_right{Diameter(root->right)};
    auto path_left{root->left ? 1 + Max(d_left) : 0},
        path_right{root->right ? 1 + Max(d_right) : 0},
        diameter{
            std::max(path_left + path_right, std::max(d_left[1], d_right[1]))};
    return {path_left, diameter, path_right};
  }

  int diameterOfBinaryTree(TreeNode *root) { return Diameter(root)[1]; }
};
