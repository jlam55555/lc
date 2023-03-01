class Solution {
public:
  int findMaxK(vector<int> &nums) {
    std::unordered_set<int> s;
    int res{-1};
    for (int i : nums) {
      if (s.count(-i)) {
        res = std::max(res, std::abs(i));
      }
      s.insert(i);
    }
    return res;
  }
};
