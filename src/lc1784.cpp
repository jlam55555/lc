class Solution {
public:
  bool checkOnesSegment(string s) {
    // Empty or singleton binary strings always return true.
    if (s.length() < 2) {
      return true;
    }

    // No leading zeroes, so we can simply see if there's ones
    // continuously.
    bool seen_zero{};
    for (auto c : s) {
      if (c == '1') {
        if (seen_zero) {
          return false;
        }
      } else {
        seen_zero = true;
      }
    }
    return true;
  }
};
