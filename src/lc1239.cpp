class Solution {
public:
  int maxLength(vector<string> &arr) {
    // unique concatenations
    vector<bitset<26>> ucs{0};
    bitset<26> bm1, bm2;
    int i, maxLen = 0;

    for (auto s : arr) {
      // gather bitset for the current string
      bm1 = 0;
      for (char c : s) {
        if (bm1[c - 'a']) {
          goto cont;
        }
        bm1.set(c - 'a');
      }

      // add any permutations that work
      for (i = ucs.size() - 1; i >= 0; --i) {
        bm2 = ucs[i];
        if (!(bm1 & bm2).any()) {
          ucs.push_back(bm1 | bm2);
          maxLen = max(maxLen, (int)(bm1 | bm2).count());
        }
      }

    cont:;
    }

    return maxLen;
  }
};
