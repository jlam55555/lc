class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    auto count{0};
    for (auto i{0}, j{0}; i < g.size() && j < s.size(); ++i, ++j) {
      while (j < s.size() && g[i] > s[j]) {
        ++j;
      }
      if (j < s.size()) {
        ++count;
      }
    }
    return count;
  }
};
