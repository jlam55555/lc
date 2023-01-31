class Solution {
public:
  string reverseOnlyLetters(string s) {
    // Count letters.
    auto count{0};
    for (auto c : s) {
      count += !!std::isalpha(c);
    }
    count >>= 1;

    for (auto i{0}, j{int(s.length()) - 1}; count--;
         std::swap(s[i++], s[j--])) {
      while (!std::isalpha(s[i]))
        ++i;
      while (!std::isalpha(s[j]))
        --j;
    }
    return s;
  }
};
