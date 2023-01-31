class Solution {
public:
  std::vector<std::string> Words(std::string_view s) {
    std::unordered_map<std::string, int> hist;
    for (auto i{0}; i < s.length();) {
      auto j{i + 1};
      while (j < s.length() && s[j] != ' ') {
        ++j;
      }
      ++hist[std::string(s.substr(i, j - i))];
      i = j + 1;
    }
    std::vector<std::string> res;
    for (const auto &i : hist) {
      if (i.second == 1) {
        res.push_back(i.first);
      }
    }
    return res;
  }

  vector<string> uncommonFromSentences(string s1, string s2) {
    return Words(s1 + " " + s2);
  }
};
