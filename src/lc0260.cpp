class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    int xr = 0, xr1 = 0, xr2 = 0, b = 1;

    // first pass
    for (auto i : nums)
      xr ^= i;

    // find a set bit
    while (!(xr & b))
      b <<= 1;

    // second pass, split numbers
    for (auto i : nums)
      (i & b ? xr1 : xr2) ^= i;

    return {xr1, xr2};
  }
};
