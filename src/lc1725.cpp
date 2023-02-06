class Solution {
public:
  int countGoodRectangles(vector<vector<int>> &rectangles) {
    int max_len{}, count{};
    for (const auto &rect : rectangles) {
      auto len{std::min(rect[0], rect[1])};
      if (len > max_len) {
        max_len = len;
        count = 1;
      } else if (len == max_len) {
        ++count;
      }
    }
    return count;
  }
};
