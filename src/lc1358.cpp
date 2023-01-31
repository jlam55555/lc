class Solution {
public:
  int numberOfSubstrings(string s) {
    list<int> next[3];

    for (int i = 0; i < s.length(); ++i) {
      next[s[i] - 'a'].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
      char c = s[i] - 'a';
      next[c].pop_front();

      if (next[(c + 1) % 3].empty() || next[(c + 2) % 3].empty()) {
        break;
      }

      ans += s.length() -
             max(next[(c + 1) % 3].front(), next[(c + 2) % 3].front());
    }

    return ans;
  }
};
