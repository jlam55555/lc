class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    std::priority_queue<int> pq{stones.begin(), stones.end()};
    while (pq.size() > 1) {
      auto largest{pq.top()};
      pq.pop();
      auto second{pq.top()};
      pq.pop();

      if (largest > second) {
        pq.push(largest - second);
      }
    }
    return pq.size() == 1 ? pq.top() : 0;
  }
};
