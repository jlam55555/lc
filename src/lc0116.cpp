/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    if (!root) {
      return root;
    }

    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      auto row = q.size();
      Node *prev = nullptr;
      for (int i{}; i < row; ++i) {
        auto n{q.front()};
        q.pop();

        if (prev != nullptr) {
          prev->next = n;
        }
        prev = n;

        if (n->left) {
          q.push(n->left);
          q.push(n->right);
        }
      }
      prev->next = nullptr;
    }

    return root;
  }
};
