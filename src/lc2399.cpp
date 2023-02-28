class Solution {
public:
  bool checkDistances(string s, vector<int> &distance) {
    for (int i{}, n(s.length()); i < n; ++i) {
      if (auto dist{distance[s[i] - 'a']};
          !((i > dist && s[i - dist - 1] == s[i]) ||
            (i + dist + 1 < n && s[i + dist + 1] == s[i]))) {
        return false;
      }
    }
    return true;
  }
};
