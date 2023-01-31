class Solution {
public:
  int CountSetBits(int n) {
    int count{0};
    while (n) {
      n &= n - 1;
      ++count;
    }
    return count;
  }

  std::string TimeToString(int h, int m) {
    static char s[6];
    std::sprintf(s, "%d:%02d", h, m);
    return std::string{s};
  }

  vector<string> readBinaryWatch(int turnedOn) {
    // Brute force.
    std::vector<string> res{};
    for (auto h{0}; h < 12; ++h) {
      for (auto m{0}; m < 60; ++m) {
        if (CountSetBits(h) + CountSetBits(m) == turnedOn) {
          res.push_back(TimeToString(h, m));
        }
      }
    }
    return res;
  }
};
