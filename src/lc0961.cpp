class Solution {
public:
  int repeatedNTimes(vector<int> &nums) {
    std::unordered_set<int> seen;
    for (auto i : nums) {
      if (seen.count(i)) {
        return i;
      }
      seen.insert(i);
    }
    throw logic_error{"shouldn't reach here"};
  }
};
