class Solution {
public:
  double findMaxAverage(const vector<int> &nums, int k) {
    // Initial window.
    auto i{0};
    auto sum{0};
    for (; i < k; ++i) {
      sum += nums[i];
    }

    // Sliding window
    auto max_sum = sum;
    for (; i < nums.size(); ++i) {
      sum += nums[i];
      sum -= nums[i - k];
      max_sum = std::max(max_sum, sum);
    }

    return max_sum / double(k);
  }
};
