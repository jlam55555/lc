class Solution {
public:
  std::vector<std::string> StrSplit(std::string_view s, char delim) {
    int pos, prev{};
    std::vector<std::string> res;
    while ((pos = s.find(delim, prev)) != std::string::npos) {
      res.emplace_back(s.substr(prev, pos - prev));
      prev = pos + 1;
    }
    res.emplace_back(s.substr(prev));
    return res;
  }

  string reverseWords(string s) {
    auto words = StrSplit(s, ' ');
    std::string res;
    for (auto it = words.rbegin(), end = words.rend(); it != end; ++it) {
      if (!it->empty()) {
        res += (res.empty() ? "" : " ") + *it;
      }
    }
    return res;
  }
};
