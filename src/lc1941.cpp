class Solution {
public:
  bool areOccurrencesEqual(string s) {
    int freqs[26]{}, freq{};
    for (auto c : s) {
      freq = ++freqs[c - 'a'];
    }
    for (int i{}; i < 26; ++i) {
      if (freqs[i] && freqs[i] != freq) {
        return false;
      }
    }
    return true;
  }
};
