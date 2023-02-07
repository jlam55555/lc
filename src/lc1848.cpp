class Solution {
public:
  int getMinDistance(vector<int> &nums, int target, int start) {
    int res{INT_MAX};
    for (int i{}; i < nums.size(); ++i) {
      if (nums[i] == target) {
        res = std::min(res, std::abs(i - start));
      }
    }
    return res;
  }
};
