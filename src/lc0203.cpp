/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    auto sentinel = new ListNode{val - 1, head};

    auto it = sentinel;
    while (it->next) {
      while (it->next && it->next->val == val) {
        it->next = it->next->next;
      }
      if (it->next) {
        it = it->next;
      }
    }

    return sentinel->next;
  }
};
