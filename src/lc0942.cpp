class Solution {
public:
  vector<int> diStringMatch(string s) {
    // How many increases before -> i
    // How many decreases before -> s.length() - i
    auto i_count{0}, d_count{0};
    std::vector<int> res;
    for (auto c : s) {
      if (c == 'I') {
        res.push_back(i_count++);
      } else {
        res.push_back(s.length() - (d_count++));
      }
    }
    // Fill in last character.
    res.push_back(i_count);
    return res;
  }
};
