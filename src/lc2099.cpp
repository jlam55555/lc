class Solution {
public:
  // Find k largest elements, while maintaining their order.
  // To do this, we get the k largest elements by sorting/quickselect.
  // Then we sort these elements by their index.
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    int n(nums.size());

    std::vector<std::pair<int, int>> nums2;
    for (int i{}; i < n; ++i) {
      nums2.push_back({nums[i], i});
    }

    // Quickselect largest k elements.
    auto it{nums2.begin() + (n - k)};
    std::nth_element(nums2.begin(), it, nums2.end());

    // Sort largest k elements by index.
    std::sort(it, nums2.end(), [](const auto &v1, const auto &v2) {
      return v1.second < v2.second;
    });

    // Gather results.
    std::vector<int> res;
    for (auto end{nums2.end()}; it != end; ++it) {
      res.push_back(it->first);
    }
    return res;
  }
};
