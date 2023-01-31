class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> seen{};
    for (int i = 0; i < nums.size(); ++i) {
      if (seen.count(target - nums[i])) {
        return vector<int>{i, seen[target - nums[i]]};
      }
      seen[nums[i]] = i;
    }

    throw invalid_argument{"no solution"};
  }
};
