class Solution {
public:
  bool noSolution(int n, vector<int> &quantities, int soln) {
    int sum = 0;
    for (auto i : quantities) {
      sum += ceil((float)i / soln);
    }
    return sum > n;
  }

  int minimizedMaximum(int n, vector<int> &quantities) {

    int maxQuantity = INT_MIN;
    for (auto i : quantities) {
      maxQuantity = max(maxQuantity, i);
    }

    // binary search to find solution
    int l = 1, r = maxQuantity + 1, m;

    while (l < r) {
      m = (l + r) / 2;
      // cout << l << " " << m << " " << r << endl;
      if (noSolution(n, quantities, m)) {
        l = m + 1;
      } else {
        r = m;
      }
      // cout << "test2 " << l << " " << m << " " << r << endl;
    }

    return l;
  }
};
