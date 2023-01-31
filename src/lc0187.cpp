class Solution {
public:
  int getRep(char c) {
    switch (c) {
    case 'A':
      return 0b00;
    case 'C':
      return 0b01;
    case 'G':
      return 0b10;
    case 'T':
      return 0b11;
    }
    throw invalid_argument{"invalid nucleotide"};
  }

  vector<string> findRepeatedDnaSequences(string s) {
    // represent each character using two bits
    // simply left shift to reduce
    // 2 * 10 = 20 bits -> can fit within a regular int

    if (s.length() < 10) {
      return {};
    }

    // build the first hash
    int i, hash = 0;
    for (i = 0; i < 10; ++i) {
      hash <<= 2;
      hash |= getRep(s[i]);
    }

    unordered_map<int, int> seen{};
    seen[hash] = 1;

    // rolling window
    vector<string> res{};
    for (; i < s.length(); ++i) {

      // add s[i], remove s[i-10]
      hash &= ~0b11000000000000000000;
      hash <<= 2;
      hash |= getRep(s[i]);

      if (++seen[hash] == 2) {
        res.push_back(s.substr(i - 9, 10));
      }
    }

    return res;
  }
};
