class Solution {
public:
  char findTheDifference(string s, string t) {
    char i{0};
    for (auto c : s) {
      i ^= c;
    }
    for (auto c : t) {
      i ^= c;
    }
    return i;
  }
};
