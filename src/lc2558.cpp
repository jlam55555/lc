class Solution {
public:
  long long pickGifts(vector<int> &gifts, int k) {
    std::priority_queue<int> pq;
    for (auto gift : gifts) {
      pq.push(gift);
    }

    for (int i{}; i < k; ++i) {
      auto max{pq.top()};
      pq.pop();
      pq.push(std::sqrt(max));
    }

    long long res{};
    while (!pq.empty()) {
      res += pq.top();
      pq.pop();
    }

    return res;
  }
};
