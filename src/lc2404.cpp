class Solution {
public:
  int mostFrequentEven(vector<int> &nums) {
    // Collect frequencies.
    std::unordered_map<int, int> freqs;
    int max_freq{};
    for (auto i : nums) {
      if (!(i & 1)) {
        max_freq = std::max(max_freq, ++freqs[i]);
      }
    }

    if (!max_freq) {
      return -1;
    }

    // Gather results.
    int res{INT_MAX};
    for (auto [i, freq] : freqs) {
      if (freq == max_freq && i < res) {
        res = i;
      }
    }
    return res;
  }
};
