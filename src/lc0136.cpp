class Solution {
public:
  int singleNumber(const vector<int> &nums) {
    auto num{0};
    for (auto i : nums) {
      num ^= i;
    }
    return num;
  }
};
