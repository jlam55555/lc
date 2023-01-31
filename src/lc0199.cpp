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
  vector<int> rightSideView(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<int> res;
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      // Clear one layer at a time.
      for (int i{}, n(q.size()); i < n; ++i) {
        auto node = q.front();
        q.pop();
        if (!i) {
          res.push_back(node->val);
        }
        if (node->right) {
          q.push(node->right);
        }
        if (node->left) {
          q.push(node->left);
        }
      }
    }
    return res;
  }
};
