class Solution {
public:
  bool divideArray(vector<int> &nums) {
    std::unordered_map<int, bool> freqs;
    for (auto n : nums) {
      freqs[n] ^= 1;
    }
    for (const auto &[unused, freq] : freqs) {
      if (freq) {
        return false;
      }
    }
    return true;
  }
};
