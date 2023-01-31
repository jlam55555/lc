class Solution {
public:
  int Gcd(int a, int b) {
    if (!b) {
      return a;
    }
    return Gcd(b, a % b);
  }

  std::vector<int> Factor(int n) {
    std::vector<int> res;
    for (auto i{1}; i <= std::sqrt(n); ++i) {
      if (!(n % i)) {
        res.push_back(i);
        res.push_back(n / i);
      }
    }
    return res;
  }

  bool IsMultiple(std::string_view part, std::string_view s) {
    auto l{s.length()}, f{part.length()};
    assert(!(l % f));
    for (auto i{0}; i < l; ++i) {
      if (s[i] != part[i % f]) {
        return false;
      }
    }
    return true;
  }

  string gcdOfStrings(string str1, string str2) {
    auto l{Gcd(str1.length(), str2.length())};
    auto factors{Factor(l)};
    std::sort(factors.begin(), factors.end(), std::greater());

    for (auto f : factors) {
      auto part{str1.substr(0, f)};
      if (IsMultiple(part, str1) && IsMultiple(part, str2)) {
        return part;
      }
    }

    return "";
  }
};
