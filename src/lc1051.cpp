class Solution {
public:
  int heightChecker(vector<int> &heights) {
    auto h2{heights};
    std::sort(h2.begin(), h2.end());
    auto res{0};
    for (auto i{0}; i < h2.size(); ++i) {
      if (h2[i] != heights[i]) {
        ++res;
      }
    }
    return res;
  }
};
