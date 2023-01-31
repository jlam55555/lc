class Solution {
public:
  int totalFruit(vector<int> &tree) {
    int len = tree.size();

    // f1 and f2 point to the first of two types of apples
    // f1 points to the one that occurs first in the
    //
    int f1 = 0, f2 = -1, f1l = 0, f2l = -1, i, lastIndex, maxLen = 0;

    for (i = 0; i < len; ++i) {

      // if this is one of f1, f2, then mark it as the latest so far in either
      if (tree[i] == tree[f1])
        f1l = i;
      else if (f2 != -1 && tree[i] == tree[f2])
        f2l = i;
      else if (f2 == -1 && tree[i] != tree[f1])
        f2 = f2l = i;

      // else it's a fruit different than f1, f2, adjust accordingly
      else {
        lastIndex = ::max(f1l, f2l);
        if (tree[lastIndex] == tree[f1l]) {
          f1 = f2l + 1;
        } else {
          f1 = f1l + 1;
          f1l = f2l;
        }
        f2 = f2l = i;
      }

      maxLen = ::max(maxLen, i - f1);
    }

    return maxLen + 1;
  }
};
