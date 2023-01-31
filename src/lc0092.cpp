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
  ListNode *reverseBetween(ListNode *h, int left, int right) {
    ListNode sentinel{-1, h}, *p{&sentinel};
    // Indices are a little funky -- start at 1 and are inclusive.
    right -= left - 1;
    // Before reversed region.
    while (--left) {
      p = h;
      h = h->next;
    }
    // Short circuit.
    if (!h) {
      return sentinel.next;
    }
    // Reversed region.
    ListNode *begin{h}, *end{nullptr};
    while (right--) {
      auto next{h->next};
      h->next = end;
      end = h;
      h = next;
    }
    // Fix up pointers.
    p->next = end;
    begin->next = h;
    return sentinel.next;
  }
};
