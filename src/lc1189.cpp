#define M(c, freq) res = std::min(res, freqs[#c[0] - 'a'] / freq)

class Solution {
public:
  int maxNumberOfBalloons(string text) {
    int freqs[26]{0};
    for (auto c : text) {
      ++freqs[c - 'a'];
    }
    auto res{INT_MAX};
    M(b, 1);
    M(a, 1);
    M(l, 2);
    M(o, 2);
    M(n, 1);
    return res;
  }
};
