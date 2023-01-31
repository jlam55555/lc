class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    bool jew[256] = {0};
    for (char c : jewels) {
      jew[c] = 1;
    }

    int count = 0;
    for (char c : stones) {
      count += jew[c];
    }

    return count;
  }
};
