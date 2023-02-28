class Solution {
public:
  // Find the longest length of 0's between a -1 and 1.
  int captureForts(vector<int> &forts) {
    int res{};
    for (int i{}, n(forts.size()); i < n;) {
      int j{i + 1};
      while (j < n && forts[i] == forts[j]) {
        ++j;
      }
      if (!forts[i] && i && j < n && std::abs(forts[i - 1] - forts[j]) == 2) {
        res = std::max(res, j - i);
      }
      i = j;
    }
    return res;
  }
};
