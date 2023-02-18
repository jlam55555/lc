class Solution {
public:
  // This is almost the same solution as lc0023.cpp.
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    int m(nums1.size()), n(nums2.size());
    std::vector<std::vector<int>> res;
    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, std::greater<>>
        pq;
    pq.push({0, 0, 0});

    while (!pq.empty() && k--) {
      auto [unused, i, j]{pq.top()};
      pq.pop();

      // Push neighbors into the pq. Avoid duplicates.
      if (!j && i != m - 1) {
        pq.push({nums1[i + 1] + nums2[j], i + 1, j});
      }
      if (j != n - 1) {
        pq.push({nums1[i] + nums2[j + 1], i, j + 1});
      }

      res.push_back({nums1[i], nums2[j]});
    }

    return res;
  }
};
