class Solution {
public:
  string fractionToDecimal(long ns, long ds) {
    if (!ns) {
      return "0";
    }

    long i{}, quot, rem;
    std::string res;
    std::unordered_map<int, int> nums;

    auto numerator = std::abs(ns), denominator = std::abs(ds);
    if (ns / numerator != ds / denominator) {
      res.push_back('-');
    }

    // Whole number part.
    auto div = std::ldiv(numerator, denominator);
    quot = div.quot;
    rem = div.rem;
    res += std::to_string(quot);
    if (!rem) {
      return res;
    }

    // Decimal part.
    res.push_back('.');
    numerator = rem * 10;
    do {
      if (nums.count(numerator)) {
        res.insert(res.length() - i + nums[numerator], "(");
        res.push_back(')');
        break;
      }

      nums[numerator] = i;
      auto div = std::ldiv(numerator, denominator);
      quot = div.quot;
      rem = div.rem;

      if (quot == 0) {
        res += "0";
      } else {
        res += std::to_string(quot);
        numerator = rem;
      }
      numerator *= 10;
      ++i;
    } while (rem);

    return res;
  }
};

// Do a manual division
// 4 / 333 = 1/10 * 40/333 = 1/100 * 400/333
// 400 mod 333 = 1 rem 67

// 670 mod 333 = 2 rem 4

// 400 mod 333 = 1 rem
