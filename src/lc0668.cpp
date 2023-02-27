class Solution {
public:
  // Count the number of elements less than v
  // in the mxn multiplication table.
  //
  // This has time complexity O(min(m, n));
  int NumElemsLt(int m, int n, int v) {
    int res{}, a{std::min(m, n)}, b{std::max(m, n)};
    for (int i{1}; i <= a; ++i) {
      res += std::min(b, v / i);
    }
    return res;
  }

  // Binary search over the solution space.
  // Time complexity: O(min(m,n) * log(m*n))
  // Space complexity: O(1)
  int findKthNumber(int m, int n, int k) {
    int l{}, r{m * n};
    while (l < r) {
      auto mid{(l + r) >> 1};
      if (NumElemsLt(m, n, mid) >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
