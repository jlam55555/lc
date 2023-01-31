class Solution {
public:
  string reformat(string s) {
    std::vector<char> l, d;
    for (auto c : s) {
      (std::isdigit(c) ? l : d).push_back(c);
    }

    // Impossible
    if (std::abs(int(l.size()) - int(d.size())) > 1) {
      return "";
    }

    int common_length = std::min(l.size(), d.size());
    std::string res;

    if (l.size() < d.size()) {
      res.push_back(d.back());
    }

    for (auto i{0}; i < common_length; ++i) {
      res.push_back(l[i]);
      res.push_back(d[i]);
    }

    if (l.size() > d.size()) {
      res.push_back(l.back());
    }
    return res;
  }
};
