class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    int minScore = INT_MAX;
    for (int i = 0; i < nums.size() - k + 1; ++i) {
      minScore = min(minScore, nums[i + k - 1] - nums[i]);
    }

    return minScore == INT_MAX ? 0 : minScore;
  }
};
