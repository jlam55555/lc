class Solution {
public:
  int countLargestGroup(int n) {
    int counts[40] = {0};

    for (int i = 1; i <= n; ++i) {
      int digitSum = 0, curr = i;
      while (curr != 0) {
        digitSum += curr % 10;
        curr /= 10;
      }

      counts[digitSum]++;
    }

    int maxGroup = -1, maxGroupCount;
    for (int i = 0; i < 40; ++i) {
      if (counts[i] > maxGroup) {
        maxGroup = counts[i];
        maxGroupCount = 1;
      } else if (counts[i] == maxGroup) {
        maxGroupCount++;
      }
    }

    return maxGroupCount;
  }
};
