class Solution {
public:
  int minSteps(string s, string t) {
    // number of different characters / 2
    int charFreqs[26] = {0};

    for (int i = 0; i < s.length(); ++i) {
      charFreqs[s[i] - 'a']++;
      charFreqs[t[i] - 'a']--;
    }

    int count = 0;
    for (int i = 0; i < 26; ++i) {
      count += abs(charFreqs[i]);
    }

    return count / 2;
  }
};
