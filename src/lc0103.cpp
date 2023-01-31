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
  // bfs
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> q{};
    vector<vector<int>> res{};

    if (!root) {
      return res;
    }

    q.push(root);
    while (!q.empty()) {
      vector<int> row{};
      for (int i = 0, s = q.size(); i < s; ++i) {
        auto r = q.front();
        q.pop();

        row.push_back(r->val);
        if (r->left) {
          q.push(r->left);
        }
        if (r->right) {
          q.push(r->right);
        }
      }
      res.push_back(row);
    }

    return res;
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    auto res = levelOrder(root);

    for (int i = 0; i < res.size(); ++i) {
      if (i % 2 == 1) {
        reverse(res[i].begin(), res[i].end());
      }
    }

    return res;
  }
};
