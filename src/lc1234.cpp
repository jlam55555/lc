class Solution {
public:
  int balancedString(string s) {
    // need to find smallest interval containing at least
    // count - n/4 of each of the elements in excess

    // converted s to easier-to-work-with numbers
    int len = s.length(), excess[4] = {-len / 4, -len / 4, -len / 4, -len / 4},
        winCounts[4] = {0}, minWinLength = len, i, left, right;
    for (i = 0; i < len; ++i) {
      switch (s[i]) {
      case 'Q':
        excess[0]++;
        s[i] = 0;
        continue;
      case 'W':
        excess[1]++;
        s[i] = 1;
        continue;
      case 'E':
        excess[2]++;
        s[i] = 2;
        continue;
      case 'R':
        excess[3]++;
        s[i] = 3;
        continue;
      }
    }

    // check if already balanced
    if (!(excess[0] || excess[1] || excess[2] || excess[3]))
      return 0;

    // criteria for successful window is that:
    // winCounts[i] >= excess[i] for every i in [0,4)
    for (left = right = 0; right < len; ++right) {
      winCounts[s[right]]++;

      // try to decrease window size by moving variable "left" to the right
      while (left < right && winCounts[s[left]] - 1 >= excess[s[left]])
        winCounts[s[left++]]--;

      // check if criteria is met
      for (i = 0; i < 4; ++i)
        if (winCounts[i] < excess[i])
          break;

      // criteria is met
      if (i == 4)
        minWinLength = ::min(minWinLength, right - left + 1);
    }

    return minWinLength;
  }
};
