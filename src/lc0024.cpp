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
  ListNode *swapPairs(ListNode *head) {
    ListNode sentinel{0, head}, *prev = &sentinel, *first, *second;

    while ((first = prev->next) && (second = first->next)) {
      prev->next = second;
      first->next = second->next;
      second->next = first;

      prev = first;
    }

    return sentinel.next;
  }
};
