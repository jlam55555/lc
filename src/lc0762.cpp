unordered_set<int> ps{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

class Solution {
public:
  unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

  int count_set_bits(int n) {
    int count = 0;

    while (n) {
      n &= n - 1;
      ++count;
    }

    return count;
  }

  int countPrimeSetBits(int left, int right) {
    int i, count;

    for (i = left, count = 0; i <= right; ++i) {
      if (primes.count(count_set_bits(i))) {
        ++count;
      }
    }

    return count;
  }
};
