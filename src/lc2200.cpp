class Solution {
public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    int n(nums.size());
    std::vector<int> res;
    for (int i{}; i < n; ++i) {
      if (nums[i] == key) {
        auto prev{res.empty() ? 0 : res.back() + 1};
        for (int j{std::max(i - k, prev)}; j <= i + k && j < n; ++j) {
          res.push_back(j);
        }
      }
    }
    return res;
  }
};
