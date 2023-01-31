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
  int maxSum = INT_MIN;

  // returns maximum single-path sum through node,
  // updates maximum two-way path as well
  int maxPathSumRec(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int leftSum = maxPathSumRec(root->left);
    int rightSum = maxPathSumRec(root->right);

    int maxSingleSum = root->val + max(0, max(leftSum, rightSum));
    int maxDoubleSum = root->val + max(0, leftSum) + max(0, rightSum);

    maxSum = max(maxSum, maxDoubleSum);

    return maxSingleSum;
  }

  int maxPathSum(TreeNode *root) {
    maxSum = INT_MIN;
    maxPathSumRec(root);
    return maxSum;
  }
};
