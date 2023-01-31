class Solution {
public:
  int romanToInt(string s) {
    int map[26] = {0};
    map['I' - 'A'] = 1;
    map['V' - 'A'] = 5;
    map['X' - 'A'] = 10;
    map['L' - 'A'] = 50;
    map['C' - 'A'] = 100;
    map['D' - 'A'] = 500;
    map['M' - 'A'] = 1000;

    int res = 0, val;
    for (int i = s.length() - 1; i >= 0; --i) {
      val = map[s[i] - 'A'];
      res += i == s.length() - 1 || val >= map[s[i + 1] - 'A'] ? val : -val;
    }

    return res;
  }
};
