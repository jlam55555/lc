/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  void Dfs(Node *root, std::vector<int> &res) {
    if (!root) {
      return;
    }
    for (const auto &c : root->children) {
      Dfs(c, res);
    }
    res.push_back(root->val);
  }

  vector<int> postorder(Node *root) {
    std::vector<int> res;
    Dfs(root, res);
    return res;
  }
};
