class Solution {
public:
  int minOperations(string s) {

    int cur = 1;
    int same = 0;
    for (char c : s) {
      same += (c - '0') ^ cur;
      cur = !cur;
    }

    return min((int)s.length() - same, same);
  }
};
