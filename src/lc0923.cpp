#define MOD 1000000007

// Brute force with multiplicity.
//
// Due to the constraints of this problem there are
// fewer than 101^2 inner loop iterations. Then it gets
// reduced to a counting problem.
class Solution {
public:
  int threeSumMulti(vector<int> &arr, int target) {
    int freqs[101]{};
    for (auto i : arr) {
      ++freqs[i];
    }

    long res{};
    for (int i{}; i < 101; ++i) {
      for (int j{i}; j < 101; ++j) {
        int k{target - i - j};
        if (k < j || k > 100) {
          continue;
        }

        int a{freqs[i]}, b{freqs[j]}, c{freqs[k]};
        long diff{};
        // nC3
        if (i == j && j == k) {
          diff = long(a) * (a - 1) * (a - 2) / 6;
        }
        // nC2 * nC1
        else if (i == j) {
          diff = long(a) * (a - 1) / 2 * c;
        } else if (j == k) {
          diff = long(b) * (b - 1) / 2 * a;
        } else if (i == k) {
          diff = long(a) * (a - 1) / 2 * b;
        }
        // nC1 * nC1 * nC1
        else {
          diff = long(a) * b * c;
        }
        res += diff;
        res %= MOD;
      }
    }
    return res;
  }
};
