class Solution {
public:
  std::string helper(std::string s) {
    int i{}, j{};
    for (; i < s.length();) {
      if (i < s.length() - 1 && std::tolower(s[i]) == std::tolower(s[i + 1]) &&
          s[i] - s[i + 1]) {
        // Skip these two letters.
        i += 2;
      } else {
        s[j++] = s[i++];
      }
    }
    return s.substr(0, j);
  }

  string makeGood(string s) {
    std::string tmp;
    while ((tmp = helper(s)) != s) {
      s = tmp;
    }
    return s;
  }
};
