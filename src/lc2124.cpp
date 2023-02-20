class Solution {
public:
  bool checkString(string s) {
    bool seen_b{};
    for (auto c : s) {
      if (c == 'b') {
        seen_b = true;
      } else if (c == 'a' && seen_b) {
        return false;
      }
    }
    return true;
  }
};
