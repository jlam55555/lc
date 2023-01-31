class Solution {
public:
  int longestPalindrome(string s) {
    std::unordered_map<char, int> freqs;
    for (auto letter : s) {
      ++freqs[letter];
    }
    auto add_1{false};
    auto longest{0};
    for (const auto &[_, freq] : freqs) {
      add_1 |= freq % 2;
      longest += freq - freq % 2;
    }
    return longest + add_1;
  }
};
