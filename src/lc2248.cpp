class Solution {
public:
  // Basically a bunch of set intersections. But we can use a vector
  // rather than sets for most of this to make things a little more
  // efficient.
  vector<int> intersection(vector<vector<int>> &nums) {
    std::sort(nums[0].begin(), nums[0].end());
    std::vector<int> res;
    std::swap(res, nums[0]);
    for (int i{1}; i < nums.size(); ++i) {
      std::unordered_set<int> arr{nums[i].begin(), nums[i].end()};
      int k{};
      for (int j{}; j < res.size(); ++j) {
        if (arr.count(res[j])) {
          res[k++] = res[j];
        }
      }
      res.resize(k);
    }
    return res;
  }
};
