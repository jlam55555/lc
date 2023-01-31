class Solution {

public:
  string restoreString(string s, vector<int> &indices) {

    std::string res(s.length(), 0);

    for (int i{}; i < s.length(); ++i) {

      res[indices[i]] = s[i];
    }

    return res;
  }
};
