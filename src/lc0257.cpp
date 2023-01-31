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
  std::string PathToString(const std::vector<int> &path) {
    if (path.empty()) {
      return {};
    }
    std::string res{std::to_string(path[0])};
    for (auto i{1}; i < path.size(); ++i) {
      res.push_back('-');
      res.push_back('>');
      res += std::to_string(path[i]);
    }
    return res;
  }

  void Dfs(TreeNode *root, std::vector<std::string> &res,
           std::vector<int> &path) {
    if (!root) {
      return;
    }

    path.push_back(root->val);
    if (!root->left && !root->right) {
      res.push_back(PathToString(path));
    }
    Dfs(root->left, res, path);
    Dfs(root->right, res, path);
    path.pop_back();
  }

  vector<string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> res{};
    std::vector<int> path{};
    Dfs(root, res, path);
    return res;
  }
};
