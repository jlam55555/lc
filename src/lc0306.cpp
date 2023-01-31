using ull = unsigned long long;

class Solution {
public:
  bool Check(std::string_view s, ull i1, ull i2) {
    // std::cout << "Checking string=" << s << " i1=" << i1 << " i2=" << i2 <<
    // std::endl;

    if (s.empty()) {
      return true;
    }

    auto i_next = i1 + i2;
    auto i = std::to_string(i_next);
    // std::string_view::starts_with() comes out in cpp20
    if (s.substr(0, i.length()) != i) {
      return false;
    }

    return Check(s.substr(i.length()), i2, i_next);
  }

  inline bool IsValid(std::string_view s) {
    return s.length() == 1 || s[0] != '0';
  }

  bool isAdditiveNumber(string num) {
    for (ull i{1}; i < num.length(); ++i) {
      for (ull j{1}; j + i < num.length(); ++j) {
        auto n1s{num.substr(0, i)}, n2s{num.substr(i, j)};
        if (!IsValid(n1s) || !IsValid(n2s)) {
          continue;
        }
        if (Check(std::string_view(num).substr(i + j), std::stoull(n1s),
                  std::stoull(n2s))) {
          return true;
        }
      }
    }
    return false;
  }
};
