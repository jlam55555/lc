class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    std::sort(arr.begin(), arr.end());

    // Find min difference/
    auto min_difference{INT_MAX};
    std::vector<std::vector<int>> pairs;
    for (auto i{1}; i < arr.size(); ++i) {
      auto diff{arr[i] - arr[i - 1]};
      if (diff < min_difference) {
        min_difference = diff;
        pairs.clear();
      }
      if (diff == min_difference) {
        pairs.push_back({arr[i - 1], arr[i]});
      }
    }

    return pairs;
  }
};
