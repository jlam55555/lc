// Algorithm: basically the same as keeping track of the
// top K elements. In this case, we're keeping track of the
// top K frequencies.
//
// Time: O(N*log(K)) (keep a maxheap of size K)
// Space: O(N) (to store frequencies)

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // Compute frequencies.
    std::unordered_map<int, int> freqs;
    for (int n : nums) {
      ++freqs[n];
    }

    // Get top frequencies.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        pq;
    for (const auto &[val, freq] : freqs) {
      pq.push({freq, val});
      if (pq.size() > k) {
        pq.pop();
      }
    }

    std::vector<int> res;
    while (!pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
  }
};
