class Solution {
public:
  int arrangeCoins(int n) {
    // n >= x(x+1)/2
    // 0 >= (1/2)x^2 + (1/2)x - n
    // x ~= (-1/2 +- sqrt((1/2)^2 - 4*(1/2)*(-n))) / 2(1/2)
    //    = (-1/2 +- sqrt(1/4 + 2n)) / 1
    //    = sqrt(1/4 + 2n) - 1/2
    return floor(sqrt(0.25 + 2. * n) - .5);
  }
};
