class Solution {
public:
  int countKDifference(vector<int> &nums, int k) {
    unordered_map<int, int> cache{};
    int count = 0;
    for (int j = 0; j < nums.size(); ++j) {
      count += cache[nums[j] - k];
      count += cache[nums[j] + k];

      ++cache[nums[j]];
    }

    return count;
  }
};
