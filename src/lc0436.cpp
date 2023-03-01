class Solution {
public:
  // Binary search.
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    // Sort intervals by start index. Also store the original index.
    std::map<int, int> sorted;
    for (int i{}, n(intervals.size()); i < n; ++i) {
      sorted[intervals[i][0]] = i;
    }
    auto end_it{sorted.end()};

    std::vector<int> res;
    for (const auto &interval : intervals) {
      auto it{sorted.lower_bound(interval[1])};
      res.push_back(it == end_it ? -1 : it->second);
    }
    return res;
  }
};
