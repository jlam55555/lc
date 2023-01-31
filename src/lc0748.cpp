class Solution {
public:
  string shortestCompletingWord(string licensePlate, vector<string> &words) {
    vector<int> hist(26, 0);
    for (char c : licensePlate) {
      if (isalpha(c)) {
        c = tolower(c);
        ++hist[c - 'a'];
      }
    }

    string minString = "";
    int minLen = INT_MAX;

    for (auto word : words) {
      auto h = hist;

      for (char c : word) {
        if (isalpha(c)) {
          c = tolower(c);
          --h[c - 'a'];
        }
      }

      for (int i = 0; i < 26; ++i) {
        if (h[i] > 0) {
          goto cont;
        }
      }

      if (word.length() < minLen) {
        minLen = word.length();
        minString = word;
      }

    cont:;
    }

    return minString;
  }
};
