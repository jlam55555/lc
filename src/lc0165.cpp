class Solution {
public:
  std::vector<std::string> StrSplit(std::string_view s, char delim) {
    int pos, prev{};
    std::vector<std::string> res;
    while ((pos = s.find(delim, prev)) != std::string::npos) {
      res.emplace_back(s.substr(prev, pos));
      prev = pos + 1;
    }
    res.emplace_back(s.substr(prev));
    return res;
  }

  int compareVersion(string version1, string version2) {
    auto p1 = StrSplit(version1, '.'), p2 = StrSplit(version2, '.');
    int len = std::max(p1.size(), p2.size());
    std::vector<int> v1(len), v2(len);
    for (int i{}; i < len; ++i) {
      if (i < p1.size()) {
        v1[i] = std::stoi(p1[i]);
      }
      if (i < p2.size()) {
        v2[i] = std::stoi(p2[i]);
      }
    }
    if (v1 < v2) {
      return -1;
    } else if (v1 > v2) {
      return 1;
    } else {
      return 0;
    }
  }
};
