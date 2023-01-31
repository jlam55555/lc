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
  int Depth(Node *n) {
    auto d{0};
    if (!n) {
      return 0;
    }
    for (const auto &c : n->children) {
      d = std::max(d, Depth(c));
    }
    return d + 1;
  }

  int maxDepth(Node *root) { return Depth(root); }
};
