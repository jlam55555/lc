// This is as straightforward of an implementation as I can
// provide, but not the most efficient.
class Solution {
public:
  std::string Convert(std::string s) {
    std::string res;
    for (auto c : s) {
      res += std::to_string(c - 'a' + 1);
    }
    return res;
  }

  int Transform(int s) {
    int res{};
    while (s) {
      res += s % 10;
      s /= 10;
    }
    return res;
  }

  int Transform(std::string s) {
    int res{};
    for (char c : s) {
      res += c - '0';
    }
    return res;
  }

  int getLucky(string s, int k) {
    auto res{Transform(Convert(s))};
    while (--k) {
      res = Transform(res);
    }
    return res;
  }
};
