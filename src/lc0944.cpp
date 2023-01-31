class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    auto h{strs.size()}, w{strs[0].length()};
    auto unsorted{0};
    for (auto j{0}; j < w; ++j) {
      for (auto i{1}; i < h; ++i) {
        if (strs[i][j] < strs[i - 1][j]) {
          ++unsorted;
          break;
        }
      }
    }
    return unsorted;
  }
};
