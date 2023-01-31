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
  void insert(ListNode *sentinel, ListNode *node) {
    auto prev = sentinel, head = prev->next;
    while (head && node->val > head->val) {
      prev = head;
      head = head->next;
    }
    prev->next = node;
    node->next = head;
  }

  ListNode *insertionSortList(ListNode *head) {
    ListNode sentinel;
    while (head) {
      auto next = head->next;
      insert(&sentinel, head);
      head = next;
    }
    return sentinel.next;
  }
};
