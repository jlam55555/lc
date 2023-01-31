class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    std::map<int, pair<int, int>> m;
    for (auto i : nums) {
      auto &[freq, unused] = m[i];
      ++freq;
    }
    auto j{0};
    for (auto &[unused, x] : m) {
      auto &[freq, v] = x;
      v = j;
      j += freq;
    }
    for (auto &i : nums) {
      i = get<1>(m[i]);
    }
    return nums;
  }
};
