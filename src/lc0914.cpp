int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

class Solution {
public:
  bool hasGroupsSizeX(vector<int> &deck) {
    std::unordered_map<int, int> freq;
    for (auto card : deck) {
      ++freq[card];
    }

    // Need to check if the gcd(cards) >= 2
    auto freq_gcd{INT_MAX};
    for (const auto &[unused, val] : freq) {
      if (freq_gcd == INT_MAX) {
        freq_gcd = val;
      } else {
        freq_gcd = gcd(freq_gcd, val);
      }
    }
    return freq_gcd > 1;
  }
};
