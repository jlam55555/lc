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
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    vector<int> res{-1, -1};
    if (!head || !head->next) {
      return res;
    }

    int first = -1, last = -1, i = 0, minDistance = INT_MAX;
    ListNode *iter = head->next, *prev = head;

    while (iter->next != nullptr) {
      if (iter->val < prev->val && iter->val < iter->next->val ||
          iter->val > prev->val && iter->val > iter->next->val) {

        //                 cout << "local minima at " << iter->val << " " << i
        //                 << endl;

        if (first < 0)
          first = i;
        if (last >= 0) {
          minDistance = min(minDistance, i - last);
        }
        last = i;
      }

      ++i;
      prev = iter;
      iter = iter->next;
    }

    if (minDistance != INT_MAX) {
      return {minDistance, last - first};
    } else {
      return {-1, -1};
    }

    //         cout << minDistance << " " << last << " " << first << endl;

    //         return res;
  }
};
