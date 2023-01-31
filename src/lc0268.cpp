class Solution {
public:
  int missingNumber(vector<int> &nums) {
    auto sum{0};
    for (auto i : nums) {
      sum += i;
    }
    auto n{nums.size()};
    return n * (n + 1) / 2 - sum;
  }
};
