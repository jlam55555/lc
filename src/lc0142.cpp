/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    // Usual tortoise-and-hare cycle finding.
    auto slow{head}, fast{head};
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        break;
      }
    }

    // No cycle.
    if (!fast || !fast->next) {
      return nullptr;
    }

    // Start an iterator from the beginning again; when it meets with
    // `slow`, we've reached the beginning point. This is due
    // to some math I won't reproduce here. See:
    // https://stackoverflow.com/a/14028962/2397327
    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};
