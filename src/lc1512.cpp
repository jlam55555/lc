class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    std::unordered_map<int, int> freq;
    for (auto i : nums) {
      ++freq[i];
    }

    auto res{0};
    for (const auto &[unused, n] : freq) {
      res += n * (n - 1) / 2;
    }
    return res;
  }
};
