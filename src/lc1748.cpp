class Solution {
public:
  int sumOfUnique(vector<int> &nums) {
    int freqs[101]{};
    for (auto i : nums) {
      ++freqs[i];
    }
    int res{};
    for (auto i{1}; i <= 100; ++i) {
      if (freqs[i] == 1) {
        res += i;
      }
    }
    return res;
  }
};
