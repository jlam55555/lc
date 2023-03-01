class Solution {
public:
  bool equalFrequency(string word) {
    int freqs[26]{}, max_freq{}, n(word.length());
    char max_char;
    for (char c : word) {
      if (++freqs[c - 'a'] > max_freq) {
        max_freq = freqs[c - 'a'];
        max_char = c - 'a';
      }
    }

    // Two scenarios:
    // 1. Maximum element has one more than the rest.
    // 2. One element has one element, rest have same as max_elem.
    bool option_1{true};
    int num_freqs_1{}, num_freqs_max{}, num_chars{};
    for (int i{}; i < 26; ++i) {
      auto f{freqs[i]};
      option_1 &= !(f && i != max_char && f != max_freq - 1);
      num_freqs_1 += f == 1;
      num_freqs_max += f == max_freq;
      num_chars += !!f;
    }
    return option_1 || (num_freqs_1 == 1 && num_freqs_max == num_chars - 1) ||
           max_freq == 1;
  }
};
