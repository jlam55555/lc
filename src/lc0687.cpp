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
  // returns the maximum length of a path up to the current node
  int dfs(TreeNode *root, int &maxLen) {
    if (!root) {
      return 0;
    }

    int pathLen = 1;
    int singlePathLen = 1;
    if (root->left) {
      int left = dfs(root->left, maxLen);
      if (root->left->val == root->val) {
        pathLen += left;
        singlePathLen += left;
      }
    }
    if (root->right) {
      int right = dfs(root->right, maxLen);
      if (root->right->val == root->val) {
        pathLen += right;
        singlePathLen = max(singlePathLen, 1 + right);
      }
    }

    maxLen = max(maxLen, pathLen - 1);
    return singlePathLen;
  }

  int longestUnivaluePath(TreeNode *root) {
    int maxLen = 0;
    dfs(root, maxLen);
    return maxLen;
  }
};
