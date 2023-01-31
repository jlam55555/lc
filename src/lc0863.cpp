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
  void getNodesAtDepth(TreeNode *root, int K, TreeNode *targetPath,
                       vector<int> &nodes) {
    if (!root)
      return;

    if (root == targetPath) {
      return;
    }

    if (K == 0) {
      nodes.push_back(root->val);
      return;
    }

    getNodesAtDepth(root->left, K - 1, targetPath, nodes);
    getNodesAtDepth(root->right, K - 1, targetPath, nodes);
  }

  int findNode(TreeNode *root, TreeNode *target, queue<TreeNode *> &stk) {
    if (!root)
      return 0;

    if (root == target || findNode(root->left, target, stk) ||
        findNode(root->right, target, stk)) {
      stk.push(root);
      return 1;
    }

    return 0;
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    // find node
    queue<TreeNode *> stk;
    findNode(root, target, stk);

    vector<int> res;

    int dist = 0;
    TreeNode *prevTarget = nullptr;
    while (!stk.empty() && K - dist >= 0) {
      getNodesAtDepth(stk.front(), K - dist, prevTarget, res);
      prevTarget = stk.front();
      stk.pop();
      ++dist;
    }

    return res;
  }
};
