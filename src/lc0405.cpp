class Solution {
public:
  char ToHexDigit(unsigned num) {
    assert(!(num & ~0xf));
    return num + (num < 10 ? '0' : 'a' - 10);
  }

  string toHex(unsigned num) {
    // Edge case.
    if (!num) {
      return "0";
    }

    auto mask{0xfu};
    std::string res{};
    while (1) {
      auto digit{num & mask};
      num >>= 4;
      res.push_back(ToHexDigit(digit));
      if (!num) {
        std::reverse(res.begin(), res.end());
        return res;
      }
    }
    throw logic_error{"never terminated"};
  }
};
