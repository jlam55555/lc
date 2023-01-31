#define MOD (1000000007)

int primes[]{2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
             43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

class Solution {
public:
  long fac(int n) {
    long res{1};
    while (n > 0) {
      res = (res * n--) % MOD;
    }
    return res;
  }

  int numPrimeArrangements(int n) {
    // Count number of primes under n.
    int i{0};
    for (; primes[i] <= n; ++i) {
    }

    return fac(i) * fac(n - i) % MOD;
  }
};
