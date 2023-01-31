class Solution {
public:
  int brokenCalc(int startValue, int target) {

    int steps = 0;

    while (target > startValue) {
      if (target % 2 == 1) {
        target++;
        steps++;
      }

      target /= 2;
      steps++;
    }

    steps += startValue - target;

    return steps;
  }
};
