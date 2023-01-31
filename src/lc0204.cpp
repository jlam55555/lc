class Solution {
public:
  // Sieve of Eratosthenes.
  int countPrimes(int n) {
    std::bitset<5000001> p;
    int i, sqrtn, count{};
    for (i = 2, sqrtn = std::sqrt(n); i <= sqrtn; ++i) {
      if (!p.test(i)) {
        std::cout << "p1 " << i << std::endl;
        ++count;
        for (auto j{i * i}; j < n; j += i) {
          p.set(j);
        }
      }
    }
    for (; i < n; ++i) {
      count += !p.test(i);
    }
    return count;
  }
};
