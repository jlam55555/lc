class Solution {
public:
  int numSplits(string s) {
    int lfreq[26] = {0}, rfreq[26] = {0}, lcount = 0, rcount = 0,
        n = s.length();

    // initialize left with single character
    ++lcount;
    ++lfreq[s[0] - 'a'];

    // initialize right with all other characters
    for (int i = 1; i < n; ++i) {
      if (rfreq[s[i] - 'a'] == 0) {
        ++rcount;
      }
      ++rfreq[s[i] - 'a'];
    }

    // start with split between index 0 and 1, check all splits
    int splits = lcount == rcount;
    for (int i = 1; i < n; ++i) {
      char transfer = s[i] - 'a';
      if (--rfreq[transfer] == 0) {
        --rcount;
      }
      if (++lfreq[transfer] == 1) {
        ++lcount;
      }

      splits += lcount == rcount;
    }

    return splits;
  }
};
