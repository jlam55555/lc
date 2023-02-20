class Solution {
public:
  int mostFrequent(vector<int> &nums, int key) {
    std::unordered_map<int, int> freqs;
    for (int i{}, n(nums.size()); i < n - 1; ++i) {
      if (nums[i] == key) {
        ++freqs[nums[i + 1]];
      }
    }
    int res{}, max_freq{};
    for (const auto &[val, freq] : freqs) {
      if (freq > max_freq) {
        max_freq = freq;
        res = val;
      }
    }
    return res;
  }
};
