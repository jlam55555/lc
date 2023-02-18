class Solution {
public:
  // Thoughts:
  // - Removing a digit that is greater than the following digit
  //   always is better than removing a digit followed by a greater
  //   digit.
  // - If there are no digits greater than the following digit,
  //   then remove from the end.
  //
  // Note that we use a stack to accomplish this. A good example
  // is the input:
  //
  // num=1234567890
  // k=9
  //
  // We cannot simply work left-to-right without a stack because
  // then we would only remove 9, and then start the second step
  // and remove letters afterwards.
  //
  // This is O(n) time and O(n) space.
  string removeKdigits(string num, int k) {
    int n(num.length()), removed{};

    // Short circuit.
    if (k >= n) {
      return "0";
    }

    // Remove digits that are greater than the following digit.
    std::string res;
    for (int i{}; i < n; ++i) {
      // Remove out-of-order digits.
      while (removed < k && !res.empty() && res.back() > num[i]) {
        res.pop_back();
        ++removed;
      }
      // Don't add leading zeros.
      if (res.empty() && num[i] == '0') {
        continue;
      }
      // Append digit to the end.
      res.push_back(num[i]);
    }

    // Remove characters from the end if we have more characters to remove.
    for (; !res.empty() && removed < k; ++removed) {
      res.pop_back();
    }

    // If there are no digits, then add a "0".
    return res.empty() ? "0" : res;
  }
};
