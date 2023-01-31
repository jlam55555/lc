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
  void reverse(ListNode *head) {
    ListNode *newHead = nullptr;
    while (head) {
      ListNode *tmp = head->next;
      head->next = newHead;
      newHead = head;
      head = tmp;
    }
  }

  void rec(ListNode *head, ListNode *headPrev, int len) {
    if (!head) {
      return;
    }

    // get pointer to next
    ListNode *nextGroup = head, *prev = nullptr, *oldHead = head;
    int i;
    for (i = 0; i < len && nextGroup; ++i) {
      prev = nextGroup;
      nextGroup = nextGroup->next;
    }

    // if even, reverse and then continue on next group
    if (i % 2 == 0) {
      prev->next = nullptr;
      reverse(headPrev->next);
      headPrev->next = prev;
      oldHead->next = nextGroup;
      prev = oldHead;
    }

    rec(nextGroup, prev, len + 1);
  }

  ListNode *reverseEvenLengthGroups(ListNode *head) {
    rec(head, nullptr, 1);
    return head;
  }
};
