class Solution {
public:
  bool isPrefixString(string s, vector<string> &words) {
    string s2{};
    for (auto s3 : words) {
      s2 += s3;
      if (s2.length() >= s.length())
        break;
    }
    return s2 == s;
  }
};
