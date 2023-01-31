class Solution {
public:
  string toLowerCase(string s) {
    for (auto &c : s) {
      c = std::tolower(c);
    }
    return s;
  }
};
