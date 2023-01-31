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
  int Tilt(TreeNode *root, int &sum) {
    if (!root) {
      return 0;
    }
    auto left_sum{Tilt(root->left, sum)}, right_sum{Tilt(root->right, sum)};
    sum += std::abs(left_sum - right_sum);
    return left_sum + right_sum + root->val;
  }

  int findTilt(TreeNode *root) {
    auto sum{0};
    Tilt(root, sum);
    return sum;
  }
};
