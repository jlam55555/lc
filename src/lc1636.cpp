// Probably not the most efficient, but fun to use std::multimap.
class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    int freqs[201]{};
    for (int i : nums) {
      ++freqs[i + 100];
    }
    std::multimap<int, int> freqs2;
    for (int i{100}; i >= -100; --i) {
      if (!freqs[i + 100]) {
        continue;
      }
      freqs2.insert({freqs[i + 100], i});
    }
    std::vector<int> res;
    for (const auto &[freq, i] : freqs2) {
      for (int j{}; j < freq; ++j) {
        res.push_back(i);
      }
    }
    return res;
  }
};
