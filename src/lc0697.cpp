struct Entry {
  int min_idx{-1};
  int max_idx;
  int freq{0};
};

class Solution {
public:
  int findShortestSubArray(vector<int> &nums) {
    // For each number, keep track of its:
    // - min idx
    // - max idx
    // - freq
    std::unordered_map<int, Entry> m;
    auto largest_freq{0};
    for (auto i{0}; i < nums.size(); ++i) {
      m[nums[i]].max_idx = i;
      if (m[nums[i]].min_idx == -1) {
        m[nums[i]].min_idx = i;
      }
      largest_freq = std::max(largest_freq, ++m[nums[i]].freq);
    }

    // Find the element with the largest freq and smallest span.
    auto res{INT_MAX};
    for (const auto &e : m) {
      if (e.second.freq == largest_freq) {
        res = std::min(res, e.second.max_idx - e.second.min_idx + 1);
      }
    }

    return res;
  }
};
