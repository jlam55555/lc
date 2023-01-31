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
  void dfs(TreeNode *root, int targetSum, std::vector<int> &stk,
           std::vector<std::vector<int>> &res) {
    if (!root) {
      return;
    }

    stk.push_back(root->val);
    targetSum -= root->val;
    if (!targetSum && !root->left && !root->right) {
      res.push_back(stk);
    }
    dfs(root->left, targetSum, stk, res);
    dfs(root->right, targetSum, stk, res);
    stk.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    std::vector<int> stk;
    std::vector<std::vector<int>> res;
    dfs(root, targetSum, stk, res);
    return res;
  }
};
