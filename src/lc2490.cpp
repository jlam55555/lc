class Solution {
public:
  bool isCircularSentence(string sentence) {
    // Check first and last character.
    int n(sentence.length());
    if (sentence[0] != sentence[n - 1]) {
      return false;
    }

    // Check connecting characters.
    for (int i{1}; i < n - 1; ++i) {
      if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
        return false;
      }
    }
    return true;
  }
};
