class Solution {
public:
  int minimumDeletions(string s) {

    int len = s.length();

    int *bsBefore = new int[len + 1];
    int *asAfter = new int[len + 1];
    bsBefore[0] = asAfter[len] = 0;

    // count b's up until this point
    for (int i = 1; i <= len; ++i) {
      bsBefore[i] = bsBefore[i - 1] + (s[i - 1] == 'b');
    }

    // count a's after this point
    for (int i = len - 1; i >= 0; --i) {
      asAfter[i] = asAfter[i + 1] + (s[i] == 'a');
    }

    // find best split
    int minDeletes = INT_MAX;
    for (int i = 0; i <= len; ++i) {
      minDeletes = min(minDeletes, bsBefore[i] + asAfter[i]);
    }

    return minDeletes;
  }
};
