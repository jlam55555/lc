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
  // create a tree from inorder[li:ri], postorder[lp:rp]
  TreeNode *buildTreeRec(vector<int> &inorder, int li, int ri,
                         vector<int> &postorder, int lp, int rp) {
    // empty tree
    if (li == ri) {
      return nullptr;
    }

    // get parent
    int parent = postorder[rp - 1];

    // get pivot between left and right
    int pivot, len;
    for (pivot = li, len = 0; pivot < ri; ++pivot, ++len) {
      if (inorder[pivot] == parent) {
        break;
      }
    }

    // recursively build tree
    return new TreeNode{
        parent, buildTreeRec(inorder, li, li + len, postorder, lp, lp + len),
        buildTreeRec(inorder, li + len + 1, ri, postorder, lp + len, rp - 1)};
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    // inorder: left, parent, right
    // postorder: left, right, parent
    int n = inorder.size();
    return buildTreeRec(inorder, 0, n, postorder, 0, n);
  }
};
