class Solution {
public:
  bool buddyStrings(string s, string goal) {
    int i1{-1}, i2{-1};

    // Edge case: s == goal, need to find a repeated letter.
    if (s == goal) {
      int freq[26]{0};
      for (auto i{0}; i < s.length(); ++i) {
        if (freq[s[i] - 'a']++) {
          return true;
        }
      }
      return false;
    }

    if (s.length() != goal.length()) {
      return false;
    }
    for (auto i{0}; i < s.length(); ++i) {
      if (s[i] == goal[i]) {
        continue;
      }
      if (i1 == -1) {
        i1 = i;
      } else if (i2 == -1) {
        i2 = i;
      } else {
        return false;
      }
    }

    // Only one letter difference.
    if (i2 == -1) {
      return false;
    }

    std::swap(s[i1], s[i2]);
    return s == goal;
  }
};
