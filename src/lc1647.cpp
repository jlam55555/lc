class Solution {
public:
  int minDeletions(string s) {
    // count freqs
    vector<int> hist(26, 0);

    for (char c : s) {
      hist[c - 'a']++;
    }

    sort(hist.begin(), hist.end(), greater<int>());

    int nextFree = hist[0] - 1, nextFreePos = 0;
    for (; nextFreePos < 26 && nextFree; ++nextFreePos) {
      if (hist[nextFreePos] == nextFree) {
        --nextFree;
      } else if (hist[nextFreePos] < nextFree) {
        break;
      }
    }
    int res = 0;
    for (int i = 1; i < 26 && hist[i]; ++i) {
      if (nextFree > hist[i]) {
        nextFree = hist[i] - 1;
        for (; nextFreePos < 26 && nextFree; ++nextFreePos) {
          if (hist[nextFreePos] == nextFree) {
            --nextFree;
          } else if (hist[nextFreePos] < nextFree) {
            break;
          }
        }
      }

      if (i != 0 && hist[i] == hist[i - 1]) {
        res += hist[i] - nextFree;
        if (nextFree) {
          nextFree--;
          for (; nextFreePos < 26 && nextFree; ++nextFreePos) {
            if (hist[nextFreePos] == nextFree) {
              --nextFree;
            } else if (hist[nextFreePos] < nextFree) {
              break;
            }
          }
        }
      }
    }

    return res;
  }
};
