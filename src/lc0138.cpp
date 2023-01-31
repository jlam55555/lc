/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  // Interleave the new nodes with the old nodes.
  Node *copyRandomList(Node *head) {
    // Duplicate nodes.
    for (auto it{head}; it;
         it = (it->next = new Node{it->val, it->next, nullptr})->next)
      ;

    // Set up random pointers.
    for (auto it{head}; it;
         it->next->random = it->random ? it->random->next : nullptr,
         it = it->next->next)
      ;

    // Split arrays.
    Node sentinel{0};
    for (auto it{head}, it2{&sentinel}; it;
         it2 = it2->next = it->next, it = it->next = it->next->next)
      ;
    return sentinel.next;
  }
};
