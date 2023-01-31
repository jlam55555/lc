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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *res = new ListNode{0}, *cur = res;
    int half_sum, sum_digit, carry = 0;
    while (l1 || l2 || carry) {
      half_sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      sum_digit = half_sum % 10;
      carry = half_sum / 10;
      cur->next = new ListNode{sum_digit};
      cur = cur->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    cur = res->next;
    delete res;
    return cur;
  }
};
