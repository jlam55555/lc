class Solution {
public:
  std::string ipToStr(const std::vector<std::string> &cur) {
    return cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3];
  }

  bool isValidPart(std::string_view s, int i, int len) {
    // Make sure valid length.
    if (i + len > s.length()) {
      return false;
    }

    // Make sure no leading zeroes.
    std::string tmp(s.substr(i, len));
    if (tmp[0] == '0' && len > 1) {
      return false;
    }

    // Make sure this number is between 0 and 255.
    auto val{std::stoi(tmp)};
    return val < 256;
  }

  void dfs(std::string_view s, int i, std::vector<std::string> &cur,
           std::vector<std::string> &res) {
    if (i == s.length() && cur.size() == 4) {
      res.push_back(ipToStr(cur));
    }
    if (i >= s.length() || cur.size() >= 4) {
      return;
    }

    for (int j{1}; j <= 3; ++j) {
      if (isValidPart(s, i, j)) {
        cur.emplace_back(s.substr(i, j));
        dfs(s, i + j, cur, res);
        cur.pop_back();
      }
    }
  }

  vector<string> restoreIpAddresses(string s) {
    std::vector<std::string> res;
    std::vector<std::string> cur;
    dfs(s, 0, cur, res);
    return res;
  }
};
