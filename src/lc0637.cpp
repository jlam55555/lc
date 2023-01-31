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
  vector<double> averageOfLevels(TreeNode *root) {
    std::queue<TreeNode *> q, q2;
    std::vector<double> res;
    q.push(root);
    while (!q.empty()) {
      long row_sum{0};
      auto row_count{0};
      while (!q.empty()) {
        auto n{q.front()};
        q.pop();

        if (!n) {
          continue;
        }
        row_sum += n->val;
        ++row_count;
        if (n->left)
          q2.push(n->left);
        if (n->right)
          q2.push(n->right);
      }
      std::swap(q, q2);
      res.push_back(row_sum / double(row_count));
    }
    return res;
  }
};
