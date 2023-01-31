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
  // O(n*log(n)) time
  // O(log(n)) space
  ListNode *sortList(ListNode *head) {
    // Handle the n=0,1 cases.
    if (!head || !head->next) {
      return head;
    }

    // Sounds like a merge sort.
    ListNode *it1{head}, *it2{head}, *prev;
    while (it2 && it2->next) {
      prev = it1;
      it1 = it1->next;
      it2 = it2->next->next;
    }

    // Split the list.
    prev->next = nullptr;

    // Sort the lists.
    it2 = sortList(it1);
    it1 = sortList(head);

    // Merge l1 and l2.
    ListNode sentinel, *it{&sentinel};
    while (it1 && it2) {
      if (it1->val < it2->val) {
        it->next = it1;
        it1 = it1->next;
      } else {
        it->next = it2;
        it2 = it2->next;
      }
      it = it->next;
    }
    if (!it1) {
      it->next = it2;
    } else {
      it->next = it1;
    }
    return sentinel.next;
  }
};
