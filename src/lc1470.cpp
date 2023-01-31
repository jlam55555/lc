class Solution {
public:
  vector<int> shuffle(vector<int> &nums, int n) {
    std::vector<int> res(2 * n);
    for (auto i{0}; i < n; ++i) {
      res[2 * i] = nums[i];
      res[2 * i + 1] = nums[i + n];
    }
    return res;
  }
};
