class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    std::unordered_set<int> seen{};
    for (auto i : nums) {
      if (seen.count(i)) {
        return true;
      }
      seen.insert(i);
    }
    return false;
  }
};
