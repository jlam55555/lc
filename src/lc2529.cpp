class Solution {
public:
  int maximumCount(vector<int> &nums) {
    int n(nums.size());

    // Find first number >= 1.
    auto it1{std::lower_bound(nums.begin(), nums.end(), 1)};
    int pos{it1 == nums.end() ? 0 : int(nums.end() - it1)};

    // Find first number <= -1.
    auto it2{std::upper_bound(nums.begin(), nums.end(), -1)};
    int neg{it2 == nums.begin() ? 0 : int(it2 - nums.begin())};

    return std::max(pos, neg);
  }
};
