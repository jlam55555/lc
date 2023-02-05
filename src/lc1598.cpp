class Solution {
public:
  int minOperations(vector<string> &logs) {
    int depth{};
    for (const auto &s : logs) {
      depth = std::max(0, depth + (s[0] == '.' ? (s[1] == '.' ? -1 : 0) : 1));
    }
    return depth;
  }
};
