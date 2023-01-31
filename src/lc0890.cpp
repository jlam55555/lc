class Solution {
public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {

    unordered_set<char> uniqTest;

    // maps to the first index that has this character
    map<char, int> firstOfType;

    // maps each character to the first equivalent character
    vector<int> eqMap(pattern.length());
    for (int i = 0; i < pattern.length(); ++i)
      if (firstOfType.find(pattern[i]) == firstOfType.end()) {
        firstOfType[pattern[i]] = i;
        eqMap[i] = i;
      } else
        eqMap[i] = firstOfType[pattern[i]];
    vector<int> typeStarts;
    for (auto it : firstOfType)
      typeStarts.push_back(it.second);

    vector<string> res;
    for (string word : words) {
      // check if word matches pattern
      for (int i = 1; i < word.length(); ++i)
        if (word[i] != word[eqMap[i]])
          goto nextWord;

      // check that all types are unique
      uniqTest.clear();
      for (int i : typeStarts)
        uniqTest.insert(word[i]);

      if (uniqTest.size() == typeStarts.size())
        res.push_back(word);

    nextWord:;
    }

    return res;
  }
};
