class Solution {
public:
  int numDifferentIntegers(string word) {
    std::unordered_set<std::string> ints;
    for (int i{}; i < word.size();) {
      // Get rid of other characters.
      while (i < word.size() && !std::isdigit(word[i])) {
        ++i;
      }

      // Get rid of leading zeros.
      while (i < word.size() - 1 && word[i] == '0' &&
             std::isdigit(word[i + 1])) {
        ++i;
      }

      // Get number.
      int j{i};
      while (j < word.size() && std::isdigit(word[j])) {
        ++j;
      }
      if (j > i) {
        ints.insert(word.substr(i, j - i));
      }
      i = j + 1;
    }
    return ints.size();
  }
};
