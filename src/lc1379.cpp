/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                          TreeNode *target) {
    TreeNode *res;

    if (!cloned)
      return nullptr;

    if (target->val == cloned->val)
      return cloned;

    if (res = getTargetCopy(nullptr, cloned->left, target))
      return res;
    else
      return getTargetCopy(nullptr, cloned->right, target);
  }
};
