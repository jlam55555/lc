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
  ListNode *oddEvenList(ListNode *head) {
    ListNode *i, *j, *k{head}, sentinel1, sentinel2, *it1{&sentinel1},
        *it2{&sentinel2};
    while (k) {
      i = k;
      k = nullptr;
      if (i) {
        j = i->next;
        it1 = it1->next = i;
        if (j) {
          k = j->next;
          it2 = it2->next = j;
        }
      }
    }

    // Join lists and mark end of list2.
    it1->next = sentinel2.next;
    it2->next = nullptr;
    return sentinel1.next;
  }
};

// 1 2 3 4 5
// i j k

// 3 4 5
// i j k

// 1
// 2

// 5
// i j k

// 1 3
// 2 4
