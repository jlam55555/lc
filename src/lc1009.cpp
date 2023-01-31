class Solution {
public:
  int bitwiseComplement(int n) {
    return n ? ~n & ((1 << int(std::log2(n) + 1)) - 1) : 1;
  }
};
