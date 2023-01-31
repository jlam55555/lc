/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  unordered_set<int> seen{};
  vector<Node *> nodes{};

  void createNodes(Node *node) {
    if (nodes.size() > node->val && nodes[node->val]) {
      return;
    }

    if (nodes.size() <= node->val) {
      nodes.resize(node->val + 1);
    }

    // set up initially with the same pointers, will fix soon
    auto nd = new Node(node->val, node->neighbors);
    nodes[node->val] = nd;

    for (auto nbr : node->neighbors) {
      createNodes(nbr);
    }
  }

  Node *cloneGraph(Node *node) {
    if (!node) {
      return node;
    }

    seen.clear();
    nodes.clear();

    createNodes(node);

    // fix neighbors
    for (int i = 1; i < nodes.size(); ++i) {
      assert(nodes[i]);

      for (int j = 0; j < nodes[i]->neighbors.size(); ++j) {
        nodes[i]->neighbors[j] = nodes[nodes[i]->neighbors[j]->val];
      }
    }

    return nodes[node->val];
  }
};
