/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *rotateRight(struct ListNode *head, int k) {
  int len = 0;
  struct ListNode *p1, *p2 = head;

  if (!head)
    return head;

  while (k-- > 0) {
    ++len;
    if (!p2->next) {
      k %= len;
      p2 = head;
    } else {
      p2 = p2->next;
    }
  }
  p1 = head;

  while (p2->next) {
    p2 = p2->next;
    p1 = p1->next;
  }

  p2->next = head;
  p2 = p1->next;
  p1->next = NULL;

  return p2;
}
