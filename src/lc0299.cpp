class Solution {
public:
  string getHint(string secret, string guess) {
    int f1[10]{}, f2[10]{};
    int b{}, c{};
    for (int i{}; i < secret.size(); ++i) {
      if (secret[i] == guess[i]) {
        ++b;
      } else {
        ++f1[secret[i] - '0'];
        ++f2[guess[i] - '0'];
      }
    }
    for (int i{}; i < 10; ++i) {
      c += std::min(f1[i], f2[i]);
    }
    return std::to_string(b) + "A" + std::to_string(c) + "B";
  }
};
