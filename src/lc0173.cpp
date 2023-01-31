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
class BSTIterator {
  TreeNode *it;
  std::stack<TreeNode *> path;

public:
  BSTIterator(TreeNode *root) : it{root} {}

  // Very nice iterative method from Pochmann.
  int next() {
    while (it) {
      path.push(it);
      it = it->left;
    }
    auto res = path.top();
    path.pop();
    it = res->right;
    return res->val;
  }

  bool hasNext() { return it || !path.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
