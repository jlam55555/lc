class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());

    // Flip negatives until we run out of negatives.
    auto i{0};
    for (; i < nums.size() && i < k && nums[i] <= 0; ++i) {
      nums[i] = -nums[i];
    }

    // If we still have a flip left, flip the smallest magnitude number we have.
    if (i < k && ((k - i) & 1)) {
      std::sort(nums.begin(), nums.end());
      nums[0] *= -1;
    }

    // Return the sum;
    auto sum{0};
    for (auto i : nums) {
      sum += i;
    }
    return sum;
  }
};
