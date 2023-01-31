class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    // For each interval, see if beginning or end of interval overlaps with
    // `newInterval`. If it does, we need a merge.
    int merged_start{newInterval[0]}, merged_end{newInterval[1]};
    std::vector<std::vector<int>> res;

    // Whether or not we have seen the merge. This is so that we insert
    // it after we finish the merge.
    auto merged{false};

    for (const auto &interval : intervals) {
      auto start{interval[0]}, end{interval[1]};

      // Overlap detected, merge.
      if (merged_start <= start && start <= merged_end ||
          merged_start <= end && end <= merged_end ||
          start <= merged_start && merged_start <= end ||
          start <= merged_end && merged_end <= end) {
        merged_start = std::min(merged_start, start);
        merged_end = std::max(merged_end, end);
        continue;
      }

      // Insert the new interval at the right time.
      if (!merged && start > merged_start) {
        res.push_back({merged_start, merged_end});
        merged = true;
      }

      res.push_back(interval);
    }

    if (!merged) {
      res.push_back({merged_start, merged_end});
    }

    return res;
  }
};
