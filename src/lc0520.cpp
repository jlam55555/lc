class Solution {
public:
  bool detectCapitalUse(string word) {
    if (word.length() == 1) {
      return true;
    } else if (std::islower(word[1])) {
      word[0] |= 0x20;
      for (const auto c : word) {
        if (!std::islower(c)) {
          return false;
        }
      }
    } else {
      for (const auto c : word) {
        if (!std::isupper(c)) {
          return false;
        }
      }
    }
    return true;
  }
};
