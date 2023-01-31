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
  TreeNode *helper(std::vector<int> &preorder, std::vector<int> &inorder,
                   int l1, int r1, int l2, int r2) {
    if (l1 == r1) {
      return nullptr;
    }

    // Get center element.
    auto val{preorder[l1]};
    int i{l2};
    while (inorder[i] != val) {
      ++i;
    }

    // Size of left and right subtrees.
    auto first = i - l2;
    auto second = (r1 - l1) - 1 - first;

    auto left =
        helper(preorder, inorder, l1 + 1, l1 + 1 + first, l2, l2 + first);
    auto right =
        helper(preorder, inorder, l1 + 1 + first, r1, l2 + first + 1, r2);
    return new TreeNode(val, left, right);
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return helper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
  }
};

// inorder: 9 3 15 20 7
// preorder: 3 9 20 15 7

// When I see the same elements in a tree that means we've seen the left branch

// inorder: left center right
// preorder: center left right

// Start with preorder, find the center element.
// Get element from inorder until center -- this forms the left tree.
// Remaining elements form the right tree.
