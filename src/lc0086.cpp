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
  ListNode *partition(ListNode *head, int x) {
    // List 1/2 head/tail
    ListNode l1h, l2h, *l1t = &l1h, *l2t = &l2h;
    while (head) {
      if (head->val < x) {
        l1t->next = head;
        l1t = head;
      } else {
        l2t->next = head;
        l2t = head;
      }
      head = head->next;
    }
    l2t->next = nullptr;
    l1t->next = l2h.next;
    return l1h.next;
  }
};
