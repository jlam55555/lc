class Solution {
public:
  string greatestLetter(string s) {
    int freqs_lower[26]{}, freqs_upper[26]{};
    for (char c : s) {
      ++(std::islower(c) ? freqs_lower : freqs_upper)[(c | 0x20) - 'a'];
    }
    for (int i{25}; i >= 0; --i) {
      if (freqs_upper[i] && freqs_lower[i]) {
        return std::string{static_cast<char>(i + 'A')};
      }
    }
    return "";
  }
};
