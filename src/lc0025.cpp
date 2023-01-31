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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode sentinel{-1, head};

    ListNode *curr = head, *next, *next_next, *grp_start;
    ListNode *next_grp = head;
    ListNode *prev_grp_end = &sentinel;

    ListNode *new_head = head;

    while (curr) {
      for (int i = 0; i < k - 1; ++i)
        if (!(curr = curr->next))
          return sentinel.next;

      grp_start = next_grp;
      next_grp = curr->next;
      curr->next = nullptr;

      ///// REGULAR REVERSE OF LL starting at grp_start
      curr = grp_start;
      next = curr->next;
      curr->next = nullptr;

      while (next) {
        next_next = next->next;
        next->next = curr;
        curr = next;
        next = next_next;
      }
      ///// END REVERSE

      // point prev group to this
      prev_grp_end->next = curr;
      prev_grp_end = grp_start;
      curr = next_grp;
      prev_grp_end->next = curr;
    }

    return sentinel.next;
  }
};
