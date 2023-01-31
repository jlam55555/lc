class Solution {
public:
  bool checkAlmostEquivalent(string word1, string word2) {
    int hist[26] = {0};
    for (char c : word1) {
      ++hist[c - 'a'];
    }

    for (char c : word2) {
      --hist[c - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      if (abs(hist[i]) > 3) {
        return false;
      }
    }

    return true;
  }
};
