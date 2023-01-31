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
  TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
    int i, j, depth = 0;
    // simple stack with array to save a little space/no dynamic allocation
    TreeNode *currentPos[30], *tree = new TreeNode[pre.size()], *tn = tree;

    if (pre.empty())
      return nullptr;

    // initialize tree and stack
    tree[0].val = pre[0];
    currentPos[0] = tree;

    for (i = 1, j = 0; i < pre.size(); ++i) {
      while (tn->val == post[j])
        tn = currentPos[--depth], ++j;

      if (!tn->left)
        tn = tn->left = tree + i;
      else
        tn = tn->right = tree + i;
      tn->val = pre[i];
      currentPos[++depth] = tn;
    }

    return tree;
  }
};
