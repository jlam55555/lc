class Solution {
public:
  int maxRepeating(string sequence, string word) {
    int maxCount = 0;

    for (int i = 0; i < sequence.length(); ++i) {
      int j = i;
      int count = 0;
      while (sequence.substr(j, word.length()) == word) {
        ++count;
        j += word.length();
      }
      maxCount = max(count, maxCount);
      i = j;
    }

    return maxCount;
  }
};
