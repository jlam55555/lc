// Idea: We can "send" one unit from arr[i] to
// arr[j] where j < i, through the following
// simple algorithm:
//
// - Increase arr[i-1], decrease arr[i]
// - Increase arr[i-2], decrease arr[i-1]
// - ...
// - Increase arr[j], decrease arr[j+1]
//
// Thus we can try to average out units to earlier
// indices. The best result grows monotonically.
class Solution {
public:
  int minimizeArrayValue(vector<int> &nums) {
    long sum{}, res{};
    for (int i{}, n(nums.size()); i < n; ++i) {
      res = std::max(res, ((sum += nums[i]) + i) / (i + 1));
    }
    return res;
  }
};
