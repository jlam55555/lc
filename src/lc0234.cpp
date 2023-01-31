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
  // reverse a linked list
  ListNode *reverse(ListNode *head) {
    ListNode *newHead = nullptr, *tmp;
    while (head) {
      tmp = head->next;
      head->next = newHead;
      newHead = head;
      head = tmp;
    }
    return newHead;
  }

  // check if two linked lists are equal up until
  // one of them ends
  bool compare(ListNode *p1, ListNode *p2) {
    while (p1 && p2) {
      if (p1->val != p2->val) {
        return false;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    return true;
  }

  bool isPalindrome(ListNode *head) {
    // split into 2
    // reverse first half
    // compare both
    ListNode *p1 = head, *p2 = head;
    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    // reverse list starting at p1
    // this actually works out really nicely
    // for both even and odd length linked lists,
    // even if the original linked list still
    // points to the second half
    p1 = reverse(p1);

    // compare two halves
    return compare(head, p1);
  }
};
