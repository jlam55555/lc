class Solution {
public:
  int distinctAverages(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::unordered_set<double> aves;
    for (int i{}, n(nums.size()); i < (n >> 1); ++i) {
      aves.insert((nums[i] + nums[n - 1 - i]) / 2.);
    }
    return aves.size();
  }
};
