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
  struct mySort {
    ListNode *node;
    int i;
    bool operator()(const mySort &m1, const mySort &m2) const {
      return m1.node->val >= m2.node->val;
    }
  };

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<mySort, vector<mySort>, mySort> pq{};

    // insert into ll
    int k = lists.size();
    for (int i = 0; i < k; ++i) {
      if (lists[i]) {
        pq.push({lists[i], i});
        lists[i] = lists[i]->next;
      }
    }

    // merge
    ListNode *res = nullptr;
    while (!pq.empty()) {
      auto next = pq.top();
      pq.pop();

      next.node->next = res;
      res = next.node;

      if (lists[next.i]) {
        pq.push({lists[next.i], next.i});
        lists[next.i] = lists[next.i]->next;
      }
    }

    // reverse
    ListNode *newHead = nullptr;
    while (res) {
      ListNode *tmp = res->next;
      res->next = newHead;
      newHead = res;
      res = tmp;
    }

    return newHead;
  }
};
