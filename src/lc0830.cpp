class Solution {
public:
  vector<vector<int>> largeGroupPositions(string s) {
    std::vector<std::vector<int>> res{};
    for (auto i{0}; i < s.length();) {
      auto j{i + 1};
      while (j < s.length() && s[j] == s[i]) {
        ++j;
      }
      if (j - i >= 3) {
        res.push_back({i, j - 1});
      }
      i = j;
    }
    return res;
  }
};
