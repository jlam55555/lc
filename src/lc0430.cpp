/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
  void flatten_rec(Node *head, Node *end) {
    if (!head) {
      return;
    }

    // if this has a child, need to flatten it recursively
    if (head->child) {
      flatten_rec(head->child, head->next);
      head->next = head->child;
      head->next->prev = head;
      head->child = nullptr;
    }

    // continue to next element
    if (head->next) {
      flatten_rec(head->next, end);
    }
    // if this is the end of a list, move this right before end
    else if (!head->next && end) {
      head->next = end;
      end->prev = head;
    }
  }

  Node *flatten(Node *head) {
    flatten_rec(head, nullptr);
    return head;
  }
};
