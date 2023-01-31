class Solution {
public:
  vector<string> string_split(string &s, char delim) {
    int prev = 0, pos;
    vector<string> res{};
    while ((pos = s.find(delim, prev)) != -1) {
      res.push_back(s.substr(prev, pos - prev));
      prev = pos + 1; // skip past the delimiter
    }
    res.push_back(s.substr(prev, pos - prev));
    return res;
  }

  bool wordPattern(string pattern, string s) {
    auto words = string_split(s, ' ');
    unordered_map<char, string> charWordMap{};
    unordered_set<string> seenWords{};

    if (words.size() != pattern.length()) {
      return false;
    }

    for (int i = 0; i < pattern.length(); ++i) {
      // letter has been seen
      if (charWordMap.count(pattern[i])) {
        if (charWordMap[pattern[i]] != words[i]) {
          return false;
        }
      }
      // letter hasn't been seen
      else {
        if (seenWords.count(words[i])) {
          return false;
        }
        charWordMap[pattern[i]] = words[i];
        seenWords.insert(words[i]);
      }
    }

    return true;
  }
};
