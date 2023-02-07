class Solution {
public:
  int secondHighest(string s) {
    int high[2]{-1, -1};
    for (char c : s) {
      auto v{c - '0'};
      if (std::isdigit(c)) {
        if (v > high[0]) {
          high[1] = high[0];
          high[0] = v;
        } else if (v != high[0] && v > high[1]) {
          high[1] = c - '0';
        }
      }
    }
    return high[1];
  }
};
