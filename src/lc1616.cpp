// Somewhat greedy solution. This is mostly based
// on @votrubac and @lee215's solutions, although my
// original solution was also similar but slightly messier.
class Solution {
public:
  bool IsPalindrome(std::string_view s) {
    for (int i{}, n(s.length()), end{n / 2}; i < end; ++i) {
      if (s[i] != s[n - 1 - i]) {
        return false;
      }
    }
    return true;
  }

  bool Check(std::string_view a, std::string_view b) {
    int n(a.length()), i{};
    for (int end{n / 2}; i < end; ++i) {
      if (a[i] != b[n - 1 - i]) {
        break;
      }
    }
    return IsPalindrome(a.substr(i, n - 2 * i)) ||
           IsPalindrome(b.substr(i, n - 2 * i));
  }

  bool checkPalindromeFormation(string a, string b) {
    return Check(a, b) || Check(b, a);
  }
};
