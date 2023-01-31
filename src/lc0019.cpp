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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // create sentinel node to get rid of edge case when first element
    // of the list is to be removed
    ListNode sentinel{0, head}, *first = &sentinel, *second = first, *toDelete;
    int i;

    // advance first n times
    for (i = 0; i < n + 1; ++i, first = first->next)
      ;

    // advance until first reaches end
    while (first)
      first = first->next, second = second->next;

    // delete
    toDelete = second->next;
    second->next = second->next->next;
    delete toDelete;

    return sentinel.next;
  }
};
