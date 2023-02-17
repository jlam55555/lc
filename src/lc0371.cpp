class Solution {
public:
  // Full-adder time!
  int getSum(int i, int j) {
    int sum{};
    for (unsigned mask{1u}, c{}; mask; mask <<= 1, c <<= 1) {
      auto a{i & mask};
      auto b{j & mask};
      sum |= a ^ b ^ c;
      c = (a & b) | (a & c) | (b & c);
    }
    return sum;
  }
};
