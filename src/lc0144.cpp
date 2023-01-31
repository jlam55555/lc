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
  // recursive traversal
  //     void rt(TreeNode *tn, vector<int> &res) {
  //         if (!tn)
  //             return;

  //         res.push_back(tn->val);

  //         rt(tn->left, res);
  //         rt(tn->right, res);
  //     }

  //     vector<int> preorderTraversal(TreeNode* root) {
  //         vector<int> res;
  //         rt(root, res);

  //         return res;
  //     }

  vector<int> preorderTraversal(TreeNode *root) {
    ::stack<TreeNode *> s;
    ::vector<int> res;

    if (!root)
      return res;

    s.push(root);
    while (!s.empty()) {
      root = s.top();
      s.pop();
      res.push_back(root->val);
      if (root->right)
        s.push(root->right);
      if (root->left)
        s.push(root->left);
    }

    return res;
  }
};
