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
  int Length(ListNode *l) { return l ? 1 + Length(l->next) : 0; }

  // Assumes l1 and l2 are the same length.
  ListNode *addTwoNumbersEq(ListNode *l1, ListNode *l2) {
    if (!l1) {
      return nullptr;
    }

    auto *next{addTwoNumbersEq(l1->next, l2->next)};
    int carry{};
    if (next && next->val >= 10) {
      next->val -= 10;
      carry = 1;
    }
    return new ListNode{l1->val + l2->val + carry, next};
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int len1, int len2) {
    int carry{};
    if (len1 == len2) {
      return addTwoNumbersEq(l1, l2);
    } else if (len1 > len2) {
      auto *next{addTwoNumbers(l1->next, l2, len1 - 1, len2)};
      if (next->val >= 10) {
        next->val -= 10;
        carry = 1;
      }
      return new ListNode{l1->val + carry, next};
    } else {
      auto *next{addTwoNumbers(l1, l2->next, len1, len2 - 1)};
      if (next->val >= 10) {
        next->val -= 10;
        carry = 1;
      }
      return new ListNode{l2->val + carry, next};
    }
  }

  // Recursive solution without reversing the linked lists.
  // Note that we do need to do one pass to count the number
  // of nodes in each list though.
  //
  // Honestly this is probably much worse than the option
  // of reversing the linked lists.
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto *next{addTwoNumbers(l1, l2, Length(l1), Length(l2))};
    if (next->val >= 10) {
      next->val -= 10;
      return new ListNode{1, next};
    }
    return next;
  }
};
