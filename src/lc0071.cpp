class Solution {
public:
  std::vector<std::string> StrSplit(std::string_view s, char delim) {
    std::vector<std::string> res;
    std::size_t pos{}, prev{};
    while ((pos = s.find(delim, prev)) != std::string::npos) {
      res.emplace_back(s.substr(prev, pos - prev));
      // Avoid the delimiter.
      prev = ++pos;
    }
    // Get last component.
    res.emplace_back(s.substr(prev, pos - prev));
    return res;
  }

  std::string StrJoin(const std::vector<std::string> s, char delim) {
    if (s.empty()) {
      return {};
    }
    std::string res = s[0];
    for (auto i{1}; i < s.size(); ++i) {
      res.push_back(delim);
      res += s[i];
    }
    return res;
  }

  string simplifyPath(string path) {
    std::vector<std::string> components;
    for (const auto &component : StrSplit(path, '/')) {
      if (component.empty() || component == ".") {
        // noop
      } else if (component == "..") {
        if (!components.empty()) {
          components.pop_back();
        }
      } else {
        components.push_back(component);
      }
    }

    return "/" + StrJoin(components, '/');
  }
};
