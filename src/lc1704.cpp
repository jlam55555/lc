class Solution {
public:
  bool halvesAreAlike(string s) {
    int counts[2][26]{}, half(s.length() / 2);
    for (int i{}; i < half; ++i) {
      ++counts[0][(s[i] | 0x20) - 'a'];
      ++counts[1][(s[i + half] | 0x20) - 'a'];
    }

    static constexpr std::array<char, 5> vowels{'a', 'e', 'i', 'o', 'u'};
    int diff{};
    for (auto v : vowels) {
      diff += counts[0][v - 'a'] - counts[1][v - 'a'];
    }
    return diff == 0;
  }
};
