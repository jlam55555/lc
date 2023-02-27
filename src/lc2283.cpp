class Solution {
public:
  bool digitCount(string num) {
    int freqs[10]{};
    for (char c : num) {
      ++freqs[c - '0'];
    }
    for (int i{}; i < num.length(); ++i) {
      if (freqs[i] != num[i] - '0') {
        return false;
      }
    }
    return true;
  }
};
