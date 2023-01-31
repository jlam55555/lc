class Solution {
public:
  int maximum69Number(int num) {
    // If any sixes, reverse last six.
    auto res{num};
    auto dig{-1};
    auto i{0};
    while (num) {
      if (num % 10 == 6) {
        dig = i;
        std::cout << "6 found at digit=" << i << std::endl;
      }
      ++i;
      num /= 10;
    }
    if (dig < 0) {
      return res;
    }

    // Turn the nth 6 into a 9
    return res + 3 * std::pow(10, dig);
  }
};
