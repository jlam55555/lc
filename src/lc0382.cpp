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

// This is the simple algorithm: fill a vector and randomly
// sample from it. This takes O(1) time, O(N) space.
//
// There is an O(N) time, O(1) space algorithm that doesn't
// require you to know the length of the inputs beforehand
// called reservoir sampling -- this chooses a random number
// from a stream of numbers by computing the correct probabilities
// of the stream elements. This is given in the official solution.
class Solution {
  std::vector<int> bs_;

public:
  Solution(ListNode *head) {
    while (head) {
      bs_.push_back(head->val);
      head = head->next;
    }
  }

  int getRandom() { return bs_[std::rand() % (bs_.size())]; }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
