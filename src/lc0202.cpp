class Solution {
public:
  int SumSquaresDigits(int n) {
    int sum{0};
    while (n) {
      sum += std::pow(n % 10, 2);
      n /= 10;
    }
    return sum;
  }

  bool isHappy(int n) {
    std::unordered_set<int> seen{};

    while (n != 1) {
      if (seen.count(n)) {
        return false;
      }
      seen.insert(n);

      n = SumSquaresDigits(n);
    }

    return true;
  }
};
