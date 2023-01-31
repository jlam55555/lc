/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *deleteDuplicates(struct ListNode *head) {
  struct ListNode *hp = head;
  while (hp && hp->next)
    if (hp->next->val == hp->val)
      hp->next = hp->next->next;
    else
      hp = hp->next;
  return head;
}
