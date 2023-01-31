class Solution {
public:
  bool checkRecord(string s) {
    auto absent{0};
    auto late_start{-1};
    for (auto i{0}; i < s.length(); ++i) {
      if (s[i] == 'A') {
        if (++absent == 2) {
          return false;
        }
      }
      if (s[i] == 'L') {
        if (late_start == -1) {
          late_start = i;
        } else {
          if (i - late_start + 1 == 3) {
            return false;
          }
        }
      } else {
        late_start = -1;
      }
    }
    return true;
  }
};
