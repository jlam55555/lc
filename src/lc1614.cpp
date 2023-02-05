class Solution {
public:
  int maxDepth(string s) {
    int depth{}, max_depth{};
    for (char c : s) {
      if (c == '(') {
        max_depth = std::max(max_depth, ++depth);
      } else if (c == ')') {
        --depth;
      }
    }
    return max_depth;
  }
};
