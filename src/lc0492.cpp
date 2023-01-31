class Solution {
public:
  vector<int> constructRectangle(int area) {
    for (int i(std::sqrt(area));; --i) {
      auto j{area / i};
      if (i * j == area) {
        return {j, i};
      }
    }
    std::logic_error{"impossible"};
  }
};
