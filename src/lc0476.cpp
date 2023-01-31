class Solution {
public:
  int findComplement(int num) {
    // Get maximum bit.
    auto max_bit{int(std::log2(num)) + 1};
    auto mask{(1ul << max_bit) - 1};
    return ~num & mask;
  }
};
