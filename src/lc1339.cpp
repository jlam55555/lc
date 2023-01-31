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
  // calculate subtree sums
  int dfsSum(TreeNode *root, int &totalSum) {
    if (!root) {
      return 0;
    }
    totalSum += root->val;
    root->val += dfsSum(root->left, totalSum) + dfsSum(root->right, totalSum);

    return root->val;
  }

  void dfsProd(TreeNode *root, long totalSum, long &maxProd) {
    if (!root) {
      return;
    }

    if (root->left) {
      maxProd = max(maxProd, root->left->val * (totalSum - root->left->val));
      dfsProd(root->left, totalSum, maxProd);
    }
    if (root->right) {
      maxProd = max(maxProd, root->right->val * (totalSum - root->right->val));
      dfsProd(root->right, totalSum, maxProd);
    }
  }

  int maxProduct(TreeNode *root) {
    // get each node's subsum
    // as well as the total sum
    int totalSum = 0;
    dfsSum(root, totalSum);

    // get max product
    long maxProd = INT_MIN;
    dfsProd(root, totalSum, maxProd);

    return maxProd % 1000000007;
  }
};
