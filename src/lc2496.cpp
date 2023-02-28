class Solution {
public:
  // I'm really lazy and use exceptions to handle
  // invalid strings here.
  int maximumValue(vector<string> &strs) {
    int res{}, val;
    for (const auto &s : strs) {
      try {
        std::size_t pos;
        val = std::stoi(s, &pos);
        if (pos != s.length()) {
          throw exception{};
        }
      } catch (std::exception e) {
        val = s.length();
      }
      res = std::max(res, val);
    }
    return res;
  }
};
