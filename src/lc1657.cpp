class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length())
      return false;

    int hist1[26] = {0};
    int hist2[26] = {0};

    for (char c : word1) {
      hist1[c - 'a']++;
    }

    for (char c : word2) {
      hist2[c - 'a']++;
    }

    // check that the same letters are used
    for (int i = 0; i < 26; ++i) {
      if (!!hist1[i] ^ !!hist2[i])
        return false;
    }

    int hh1[100000] = {0};
    int hh2[100000] = {0};
    for (int i = 0; i < 26; ++i) {
      hh1[hist1[i]]++;
      hh2[hist2[i]]++;
    }

    for (int i = 0; i < 100000; ++i) {
      if (hh1[i] != hh2[i])
        return false;
    }

    return true;
  }
};
