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
  // morris traversal
  void recoverTree(TreeNode *root) {

    TreeNode *curr, *pre;
    TreeNode *prev = nullptr;
    TreeNode *ooo[2] = {nullptr, nullptr};

    curr = root;
    while (curr) {
      if (!curr->left) {
        if (prev && curr->val < prev->val && !ooo[0])
          ooo[0] = prev;
        if (prev && curr->val < prev->val && ooo[0])
          ooo[1] = curr;
        prev = curr;
        curr = curr->right;
      } else {
        pre = curr->left;

        while (pre->right && pre->right != curr)
          pre = pre->right;

        if (!pre->right) {
          pre->right = curr;
          curr = curr->left;
        } else {
          if (prev && curr->val < prev->val && !ooo[0])
            ooo[0] = prev;
          if (prev && curr->val < prev->val && ooo[0])
            ooo[1] = curr;
          prev = curr;

          curr = curr->right;
          pre->right = nullptr;
        }
      }
    }

    ::swap(ooo[0]->val, ooo[1]->val);
  }
};
