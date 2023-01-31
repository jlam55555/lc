class Solution {
public:
  int numberOfSteps(int num) {
    auto res{0};
    while (num) {
      if (num & 1) {
        --num;
      } else {
        num >>= 1;
      }
      ++res;
    }
    return res;
  }
};
