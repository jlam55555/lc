class Solution {
public:
  // Awful coding but I'm kinda out of it.
  std::string pad(std::string s) {
    while (s.length() < 3) {
      s = '0' + s;
    }
    return s;
  }

  string thousandSeparator(int n) {
    std::string res;
    auto s = std::to_string(n % 1000);
    n /= 1000;
    res = n ? pad(s) : s;
    while (n) {
      s = std::to_string(n % 1000);
      n /= 1000;
      res = (n ? pad(s) : s) + "." + res;
    }
    return res;
  }
};
