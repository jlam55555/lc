class Solution {
public:
  unordered_set<string> searched{};

  bool starts_with(string s, string prefix) {
    if (s.length() < prefix.length()) {
      return false;
    }
    for (int i = 0; i < prefix.length(); ++i) {
      if (s[i] != prefix[i]) {
        return false;
      }
    }
    return true;
  }

  bool wordBreak(string s, vector<string> &wordDict) {

    if (searched.count(s)) {
      return false;
    }

    if (s.empty()) {
      return true;
    }

    for (string word : wordDict) {
      if (starts_with(s, word)) {
        if (wordBreak(s.substr(word.length()), wordDict)) {
          return true;
        }
      }
    }

    searched.insert(s);
    return false;
  }
};
