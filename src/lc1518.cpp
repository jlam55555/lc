class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    auto res{numBottles};
    auto empty{numBottles};
    while (numBottles = empty / numExchange) {
      res += numBottles;
      empty -= numBottles * (numExchange - 1);
    }
    return res;
  }
};
