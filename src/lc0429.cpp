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
  vector<vector<int>> levelOrder(Node *root) {
    std::vector<std::vector<int>> res;
    if (!root) {
      return res;
    }

    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      res.push_back({});
      for (int i{}, n(q.size()); i < n; ++i) {
        const auto *node{q.front()};
        q.pop();

        res.back().push_back(node->val);
        for (auto *child : node->children) {
          q.push(child);
        }
      }
    }
    return res;
  }
};
