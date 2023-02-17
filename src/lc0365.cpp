class Solution {
public:
  int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

  // This works because of Bezout's identity:
  // For integers a, b, we can find integers c, d s.t.
  // ac + bd = gcd(a, b).
  //
  // If c, d are positive, then we fill the bucket that many
  // times; if they are negative, then we empty the bucket
  // that many times. Note that we must be careful about the
  // order of filling and emptying the buckets if we actually
  // want to recreate this procedure; basically we have to
  // keep the amount of water w in the buckets s.t.
  // 0 <= w <= a + b. However, the question doesn't ask us
  // to specify the order in which we fill and empty bottles,
  // so we don't have to worry about this.
  //
  // This means that we can get to any multiple of
  // gcd(a, b) that is less than the sum of a and b.
  //
  // Note that this problem can also be solved using a BFS
  // (This also passes Leetcode verification.)
  bool canMeasureWater(int a, int b, int t) {
    return t <= a + b && !(t % gcd(a, b));
  }
};
