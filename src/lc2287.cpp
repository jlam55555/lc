// Generalized version of lc1189.cpp
class Solution {
public:
  int rearrangeCharacters(string s, string target) {
    int freqs[26]{}, target_freqs[26]{};
    for (char c : s) {
      ++freqs[c - 'a'];
    }
    for (char c : target) {
      ++target_freqs[c - 'a'];
    }
    int res{INT_MAX};
    for (int i{}; i < 26; ++i) {
      if (target_freqs[i]) {
        res = std::min(res, freqs[i] / target_freqs[i]);
      }
    }
    return res;
  }
};
