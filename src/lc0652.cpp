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

// The general algorithm is the same as given in the official solution. The main
// difference is that we implement a custom key type to lookup subtrees, rather
// than using strings. Strings are probably a better idea though.
// This solution is O(N) time (traverse the tree once) and O(N) space
// (duplicate each canonical subtree).
//
// Another good solution is to use a rolling tree hash approach, such as Merkle
// trees.
class Solution {

  // We only need to store counts of canonical nodes.
  using CanonicalNode = int;

  // We recursively define a "canonical subtree" or "canonical node" as a
  // tree that is either empty, or is uniquely defined by the tuple
  // (root->val, root->left_canonical, root->right_canonical), and whose
  // structure and values matches at least one subtree in the original tree.
  //
  // Here, we create a lookup table for canonical subtrees using a custom
  // data structure and hash function. This can be greatly simplified if
  // we implement it as a string, since strings are already comparable and
  // hashable by default. Each canonical subtree is mapped to its count.
  struct CanonicalNodeKey {
    int val;
    CanonicalNode *canon_left, *canon_right;
    bool operator==(const CanonicalNodeKey &cnk) const {
      return val == cnk.val && canon_left == cnk.canon_left &&
             canon_right == cnk.canon_right;
    }
    static constexpr auto Hash = [](const auto &cnk) {
      return std::hash<CanonicalNode *>()(cnk.canon_left) ^
             std::hash<CanonicalNode *>()(cnk.canon_right) ^ cnk.val;
    };
  };
  std::unordered_map<CanonicalNodeKey, CanonicalNode,
                     decltype(CanonicalNodeKey::Hash)>
      canon_{0, CanonicalNodeKey::Hash};

public:
  // Recursive algorithm to generate the canonical node representing `root`.
  // - Base case: `root == nullptr`, return `nullptr`.
  // - Otherwise, we generate the canonical nodes for the left and
  //   right subtrees, and check if there is a canonical subtree for the
  //   root node. If there isn't one, we create one and set its count to
  //   1. Once a canonical subtree's count reaches 2, we add it to the result
  //   array. Then we return the canonical node for the root.
  CanonicalNode *Dfs(TreeNode *root, std::vector<TreeNode *> &res) {
    if (!root) {
      return nullptr;
    }

    auto *canon_left{Dfs(root->left, res)};
    auto *canon_right{Dfs(root->right, res)};

    // Find the current canonical node with the canonical
    // left and right subtrees `canon_left` and `canon_right`.
    auto *canon_root = &canon_[{root->val, canon_left, canon_right}];

    // If this canonical node is a duplicate, save the current subtree to
    // the results array.
    if (++*canon_root == 2) {
      res.push_back(root);
    }
    return canon_root;
  }

  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    std::vector<TreeNode *> res;
    Dfs(root, res);
    return res;
  }
};
