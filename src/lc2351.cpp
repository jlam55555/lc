class Solution {
public:
  char repeatedCharacter(string s) {
    int seen[26]{};
    for (char c : s) {
      if (seen[c - 'a']++) {
        return c;
      }
    }
    throw logic_error{"shouldn't happen"};
  }
};
