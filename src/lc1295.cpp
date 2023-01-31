class Solution {
public:
  int findNumbers(vector<int> &nums) {
    auto res{0};
    for (auto num : nums) {
      res += int(std::ceil(std::log10(num + 1))) % 2 == 0;
    }
    return res;
  }
};
