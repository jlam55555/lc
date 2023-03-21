// Very similar solution to lc1047.cpp (Remove All Adjacent
// Duplicates in String).
class Solution {
public:
  // Similar to std::basic_string::ends_with() for C++20.
  bool EndsWith(std::string_view s1, std::string_view s2) {
    int n1(s1.length()), n2(s2.length());
    return n1 >= n2 && s1.substr(n1 - n2) == s2;
  }

  string removeOccurrences(string s, string part) {
    std::string res{};
    int n(part.length());

    for (char c : s) {
      res.push_back(c);
      while (EndsWith(res, part)) {
        res.resize(res.length() - n);
      }
    }

    return res;
  }
};
