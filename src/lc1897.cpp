class Solution {
public:
  // Make sure each letter has a frequency divisible
  // by the number of words.
  bool makeEqual(vector<string> &words) {
    int freqs[26]{}, n(words.size());
    for (const auto &word : words) {
      for (auto c : word) {
        ++freqs[c - 'a'];
      }
    }
    for (int i{}; i < 26; ++i) {
      if (freqs[i] % n) {
        return false;
      }
    }
    return true;
  }
};
