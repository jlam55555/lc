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
  int maxLevelSum(TreeNode *root) {

    queue<TreeNode *> q{};

    q.push(root);
    TreeNode *lastOfRow = root;
    int levelSum = 0, i = 1;
    int maxLevelSum = INT_MIN, maxLevelSumI = 0;

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      levelSum += node->val;

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      if (node == lastOfRow) {
        if (levelSum > maxLevelSum) {
          maxLevelSum = levelSum;
          maxLevelSumI = i;
        }

        levelSum = 0;
        i++;
        if (!q.empty()) {
          lastOfRow = q.back();
        }
      }
    }

    return maxLevelSumI;
  }
};
