// This isn't the most efficient, since we only need to look
// up original times powers of 2. But I'm lazy.
class Solution {
public:
  int findFinalValue(vector<int> &nums, int original) {
    std::unordered_set<int> lookup;
    for (auto i : nums) {
      lookup.insert(i);
    }
    while (lookup.count(original)) {
      original <<= 1;
    }
    return original;
  }
};
