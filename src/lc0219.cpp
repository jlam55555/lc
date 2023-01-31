class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    std::unordered_map<int, int> last_seen{};
    for (auto i{0}; i < nums.size(); ++i) {
      if (last_seen[nums[i]] && i + 1 - last_seen[nums[i]] <= k) {
        return true;
      }
      last_seen[nums[i]] = i + 1;
    }
    return false;
  }
};
