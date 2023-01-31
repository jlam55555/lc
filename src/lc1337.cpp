class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        std::greater<std::vector<int>>>
        pq;
    for (auto i{0}; i < mat.size(); ++i) {
      auto s{0};
      for (const auto t : mat[i]) {
        s += t;
      }
      pq.push({s, i});
    }

    std::vector<int> res;
    for (auto i{0}; i < k; ++i) {
      res.push_back(pq.top()[1]);
      pq.pop();
    }
    return res;
  }
};
