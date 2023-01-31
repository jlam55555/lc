/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {

  if (!headA || !headB)
    return NULL;

  struct ListNode *last = headA, *slow, *fast, *intersection;

  // get last element in list1
  while (last->next)
    last = last->next;

  last->next = headA;

  // two pointer technique (Floyd's cycle detection technique)
  slow = headB, fast = headB;
  do {
    if (!fast || !fast->next) {
      last->next = NULL;
      return NULL;
    }

    slow = slow->next;
    fast = fast->next->next;
  } while (slow != fast);

  intersection = headB;
  while (intersection != slow) {
    intersection = intersection->next;
    slow = slow->next;
  }

  last->next = NULL;
  return intersection;
}
