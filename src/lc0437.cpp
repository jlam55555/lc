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
  int pathSum(TreeNode *root, int targetSum, std::vector<int> &s) {
    if (!root) {
      return 0;
    }
    s.push_back(root->val);

    int res{};
    long sum{};
    for (int i(s.size() - 1); i >= 0; --i) {
      res += (sum += s[i]) == targetSum;
    }

    res += pathSum(root->left, targetSum, s);
    res += pathSum(root->right, targetSum, s);

    s.pop_back();
    return res;
  }

  int pathSum(TreeNode *root, int targetSum) {
    std::vector<int> s;
    return pathSum(root, targetSum, s);
  }
};
