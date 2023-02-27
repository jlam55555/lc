// This is the k=1 case of lc0402.cpp. Note that this can be
// easily brute forced by removing each instance of the digit
// and checking it against the other possible results to find
// the maximum possible result. But we can use the same logic
// from question 402 to short-circuit this operation.
class Solution {
public:
  string removeDigit(string number, char digit) {
    std::string res;
    for (int i{}, n(number.length()); i < n - 1; ++i) {
      if (number[i] == digit && number[i + 1] > digit) {
        return number.substr(0, i) + number.substr(i + 1);
      }
    }
    auto pos{number.rfind(digit)};
    return number.substr(0, pos) + number.substr(pos + 1);
  }
};
