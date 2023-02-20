class Solution {
public:
  // Choose the smallest two and the largest two integers.
  int maxProductDifference(vector<int> &nums) {
    // Find largest and smallest elements in O(n) time.
    auto a{INT_MIN}, b{a}, c{INT_MAX}, d{c};
    for (auto i : nums) {
      if (i > a) {
        b = a;
        a = i;
      } else if (i > b) {
        b = i;
      }
      if (i < d) {
        c = d;
        d = i;
      } else if (i < c) {
        c = i;
      }
    }
    return (a * b) - (c * d);
  }
};
