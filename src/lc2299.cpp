class Solution {
public:
  bool strongPasswordCheckerII(string password) {
    int n(password.length());
    std::string special_chars{"!@#$%^&*()-+"};
    std::unordered_set<char> special{special_chars.begin(),
                                     special_chars.end()};
    bool at_least_8{n >= 8}, has_upper{}, has_lower{}, has_digit{},
        has_special{};
    for (int i{}; i < n; ++i) {
      auto c{password[i]};
      // Check existence.
      if (std::islower(c)) {
        has_lower = true;
      } else if (std::isupper(c)) {
        has_upper = true;
      } else if (std::isdigit(c)) {
        has_digit = true;
      } else if (special.count(c)) {
        has_special = true;
      }
      // Check repeats.
      if (i && password[i] == password[i - 1]) {
        return false;
      }
    }
    return at_least_8 && has_upper && has_lower && has_digit && has_special;
  }
};
