class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    // Possibilities:
    // - All negative numbers --> negative, choose smallest negatives
    // - All positive numbers --> positive, choose largest numbers
    // - One negative numbers -->

    // If all negative, find smallest three.
    // If two positives and a negative, return them.
    // Otherwise, try to find a matching pair and a positive.

    // Edge case: two positives and a negative.
    if (nums.size() == 3) {
      return nums[0] * nums[1] * nums[2];
    }

    std::sort(nums.begin(), nums.end());

    // All nonpositive: multiply least absolute value.
    if (nums.back() <= 0) {
      auto i{nums.size() - 1};
      return nums[i] * nums[i - 1] * nums[i - 2];
    }

    // Get largest positive, and larger of positive/negative pair (if
    // applicable).
    auto max_subproduct{INT_MIN};
    if (nums[nums.size() - 3] >= 0) {
      max_subproduct = nums[nums.size() - 3] * nums[nums.size() - 2];
    }
    if (nums[1] <= 0) {
      max_subproduct = std::max(max_subproduct, nums[0] * nums[1]);
    }

    return nums.back() * max_subproduct;
  }
};
