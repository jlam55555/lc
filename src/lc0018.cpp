class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums, int start, int target) {
    int len = nums.size();
    int i, j, k, iv, jv, kv, sum;
    ::vector<vector<int>> res;

    for (i = start, iv = nums[i]; i < len - 2; iv = nums[++i]) {

      // ignore duplicates in i
      if (i != start && iv == nums[i - 1])
        continue;

      for (j = i + 1, k = len - 1; j < k;) {
        jv = nums[j], kv = nums[k], sum = iv + jv + kv;
        if (sum == target)
          // zero is placeholder for 4-sum
          res.push_back(vector{0, iv, jv, kv});
        if (sum <= target) {
          while (j < k && jv == nums[j + 1])
            ++j;
          ++j;
        }
        if (sum >= target) {
          while (j < k && kv == nums[k - 1])
            --k;
          --k;
        }
      }
    }

    return res;
  }

  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int len = nums.size(), i;
    vector<vector<int>> res;

    // edge case: iterators would be invalid
    if (len < 4)
      return res;

    ::sort(nums.begin(), nums.end());

    for (i = 0; i < len - 3; ++i) {
      if (i && nums[i] == nums[i - 1])
        continue;

      for (vector<int> threeSums : threeSum(nums, i + 1, target - nums[i])) {
        threeSums[0] = nums[i];
        res.push_back(threeSums);
      }
    }

    return res;
  }
};
