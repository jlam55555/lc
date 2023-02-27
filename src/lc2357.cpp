class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    std::unordered_set<int> uniq;
    for (auto i : nums) {
      if (i) {
        uniq.insert(i);
      }
    }
    return uniq.size();
  }
};
