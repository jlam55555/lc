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
  // place camera if not a leaf node and either child is not watched,
  // or if root node and not watched
  // if placing camera, want to mark the parent as watched
  int count = 0;
  void dfs(TreeNode *root, TreeNode *parent) {
    if (!root) {
      return;
    }

    // if leaf node (and not root node), don't add camera
    if (parent && !root->left && !root->right) {
      // cout << "leaf" << endl;
      return;
    }

    // if already watched, don't add camera
    if (root->val) {
      // cout << "already watched" << endl;
      return;
    }

    // check if exists a non-watched child; if so, watch the
    // current node and its parents
    dfs(root->left, root);
    dfs(root->right, root);

    bool unwatchedChild = false;
    if (root->left && !root->left->val) {
      unwatchedChild = true;
    } else if (root->right && !root->right->val) {
      unwatchedChild = true;
    }

    if (unwatchedChild) {
      ++count;
      root->val = 1;
      if (parent) {
        parent->val = 1;
      }
      // cout << "unwatched child" << endl;
    } else {
      // cout << "children watched" << endl;
    }

    // if root and not being watched, add camera
    if (!parent && !root->val) {
      ++count;
      // cout << "root camera" << endl;
      root->val = 1;
      return;
    }
  }

  int minCameraCover(TreeNode *root) {
    count = 0;
    dfs(root, nullptr);
    return count;
  }
};

// configuration:

// Two leaf nodes at bottom:
// put camera on top node
//   C
// N   N

//   N
// C   C

// always can put camera at height 1
// if neither child has a camera, add a camera
// edge case: trees with height 0
