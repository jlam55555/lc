class Solution {
public:
  int findClosestNumber(vector<int> &nums) {
    int res{INT_MAX};
    for (int i : nums) {
      if (std::abs(i) < std::abs(res) ||
          std::abs(i) == std::abs(res) && i > res) {
        res = i;
      }
    }
    return res;
  }
};
