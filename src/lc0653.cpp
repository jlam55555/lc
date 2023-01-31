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
  bool Traverse(TreeNode *root, int k, std::unordered_set<int> &found) {
    if (!root) {
      return false;
    }

    if (found.count(k - root->val)) {
      return true;
    }
    found.insert(root->val);
    return Traverse(root->left, k, found) || Traverse(root->right, k, found);
  }

  bool findTarget(TreeNode *root, int k) {
    std::unordered_set<int> found;
    return Traverse(root, k, found);
  }
};
