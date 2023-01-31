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
  // remainingSum = limit - (sum of nodes above tn)
  // returns maximum sum of nodes below this (or INT_MIN if it's to be deleted)
  int rt(TreeNode *tn, int remainingSum) {
    int left = 0, right = 0, msopbt;
    bool isLeaf;

    isLeaf = !tn->left && !tn->right;

    if (tn->left && (left = rt(tn->left, remainingSum - tn->val)) == INT_MIN)
      tn->left = nullptr;

    if (tn->right && (right = rt(tn->right, remainingSum - tn->val)) == INT_MIN)
      tn->right = nullptr;

    // maximum sum of path below this
    msopbt = max(left, right);
    return msopbt == INT_MIN || remainingSum > msopbt + tn->val ||
                   (!isLeaf && !tn->left && !tn->right)
               ? INT_MIN
               : msopbt + tn->val;
  }

  TreeNode *sufficientSubset(TreeNode *root, int limit) {
    if (!root)
      return root;

    TreeNode sentinel{0, root, nullptr};
    rt(&sentinel, limit);
    return sentinel.left;
  }
};
