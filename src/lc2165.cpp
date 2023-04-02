// Fairly straightforward question and solution.
class Solution {
public:
  long long smallestNumber(long long num) {
    if (!num) {
      return num;
    }

    // Get sign.
    bool sign{num >= 0};

    // Get digits.
    num = sign ? num : -num;
    std::vector<int> digits;
    while (num) {
      digits.push_back(num % 10);
      num /= 10;
    }

    if (!sign) {
      std::sort(digits.rbegin(), digits.rend());
    } else {
      std::sort(digits.begin(), digits.end());
      // Move first non-zero digit before any zeros,
      // if applicable.
      if (!digits.front() && digits.back()) {
        int i{1};
        while (i < digits.size() && !digits[i]) {
          ++i;
        }
        std::swap(digits[0], digits[i]);
      }
    }

    long long res{};
    for (auto d : digits) {
      res *= 10;
      res += d;
    }
    return sign ? res : -res;
  }
};
