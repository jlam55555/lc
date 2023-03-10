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

    queue<Node *> q;
    q.push(root);

    Node *prev = nullptr, *endOfRow = root;

    // order level-order traversal (BFS)
    while (!q.empty()) {
      auto n = q.front();
      q.pop();

      if (prev) {
        prev->next = n;
      }
      prev = n;

      if (n->left) {
        q.push(n->left);
      }

      if (n->right) {
        q.push(n->right);
      }

      if (n == endOfRow) {
        prev = nullptr;
        endOfRow = q.back();
      }
    }

    return root;
  }
};
