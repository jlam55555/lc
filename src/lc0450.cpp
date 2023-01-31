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
  TreeNode *constructBst(TreeNode *left, TreeNode *right) {
    if (!left) {
      return right;
    }

    // go all the way down the right node of left
    auto bottomRight = left;
    while (bottomRight->right) {
      bottomRight = bottomRight->right;
    }
    bottomRight->right = right;
    return left;
  }

  TreeNode *deleteNodeRec(TreeNode *root, TreeNode *parent, int key) {
    if (!root) {
      return root;
    }

    auto left = deleteNodeRec(root->left, root, key),
         right = deleteNodeRec(root->right, root, key);

    if (root->val == key) {
      // this node is to be deleted;
      // construct a bst from the two children
      auto newRoot = constructBst(left, right);
      if (parent) {
        if (parent->left == root) {
          parent->left = newRoot;
        } else {
          parent->right = newRoot;
        }
      }
      return newRoot;
    } else {
      // not deleted
      return root;
    }
  }

  TreeNode *deleteNode(TreeNode *root, int key) {
    return deleteNodeRec(root, nullptr, key);
  }
};
