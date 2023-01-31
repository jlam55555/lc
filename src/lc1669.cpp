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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    // get node b+1
    ++b;
    ListNode *endp = list1;
    while (b-- > 0) {
      endp = endp->next;
    }

    // point end of list2 to b
    ListNode *l2p = list2;
    while (l2p->next) {
      l2p = l2p->next;
    }
    l2p->next = endp;

    // get node a-1
    --a;
    ListNode *startp = list1;
    while (a-- > 0) {
      startp = startp->next;
    }

    // point start to list 2
    startp->next = list2;

    return list1;
  }
};
