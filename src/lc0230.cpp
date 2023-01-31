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
  // Iterative inorder traversal.
  int kthSmallest(TreeNode *it, int k) {
    int i{};
    std::stack<TreeNode *> stk;
    while (1) {
      while (it) {
        stk.push(it);
        it = it->left;
      }
      auto next = stk.top();
      stk.pop();
      it = next->right;
      if (++i == k) {
        return next->val;
      }
    }
    throw logic_error{"shouldn't happen"};
  }
};
