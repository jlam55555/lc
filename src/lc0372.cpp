#define MOD 1337

class Solution {
public:
  // Generalize repeated squaring to base 10.
  int superPow(int a, vector<int> &b) {
    a %= MOD;

    int res{1};
    for (int i{int(b.size()) - 1}, it{a}, prod{1}; i >= 0;
         --i, it = prod, prod = 1) {
      for (int j{}; j < 10; ++j) {
        if (j == b[i]) {
          res *= prod;
          res %= MOD;
        }
        prod *= it;
        prod %= MOD;
      }
    }

    return res;
  }
};
