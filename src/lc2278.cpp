class Solution {
public:
  int percentageLetter(string s, char letter) {
    int count{};
    for (auto i : s) {
      count += i == letter;
    }
    return count * 100 / s.length();
  }
};
