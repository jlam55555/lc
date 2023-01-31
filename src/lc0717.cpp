class Solution {
public:
  bool isOneBitCharacter(vector<int> &bits) {
    // Only true if we have a pattern like ....01111110
    // with an even number of ones before the zero.
    auto i{int(bits.size()) - 2};
    while (i >= 0 && bits[i]) {
      --i;
    }
    auto num_is = bits.size() - 2 - i;
    return num_is % 2 == 0;
  }
};
