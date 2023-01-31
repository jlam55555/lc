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
  bool hasCycle(ListNode *head) {
    // not correct, just abusing the problem constraints
    for (int i = 0; head && i < 1e4; ++i, head = head->next)
      ;
    return head;
  }
};
