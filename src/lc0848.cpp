// Start from the end, build up a cumulative shift amount
// for each character.
class Solution {
public:
  char Shift(char c, int x) { return ((c - 'a') + x) % 26 + 'a'; }

  string shiftingLetters(string s, vector<int> &shifts) {
    int n(s.length());
    for (int i{n - 1}, cum_shift{}; i >= 0; --i) {
      cum_shift += shifts[i] % 26;
      s[i] = Shift(s[i], cum_shift);
    }
    return s;
  }
};
