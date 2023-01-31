class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    // cumulative sum problem
    unordered_map<int, int> prevSums{};

    int cumSum = 0, count = 0;
    for (auto i : nums) {
      ++prevSums[cumSum];
      cumSum += i;

      // want to find how many positions such
      // that net change is k
      count += prevSums[cumSum - k];
    }

    return count;
  }
};
