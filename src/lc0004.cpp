class Solution {
public:
  double findMedianSortedArrays(vector<int> &n1, vector<int> &n2) {
    int l1 = n1.size(), l2 = n2.size(), k = (l1 + l2) / 2, lo = max(0, k - l2),
        hi = min(k, l1), i = (lo + hi) / 2, j = k - i, hol = INT_MIN,
        lor = INT_MAX;

    while (!(!i || j >= l2 || n1[i - 1] <= n2[j]) ||
           !(!j || i >= l1 || n2[j - 1] <= n1[i])) {
      if (i && j < l2 && n1[i - 1] > n2[j])
        hi = i - 1;
      if (j && i < l1 && n2[j - 1] > n1[i])
        lo = i + 1;
      i = (lo + hi) / 2, j = k - i;
    }

    // find highest of left (in l3)
    if (i)
      hol = n1[i - 1];
    if (j)
      hol = max(hol, n2[j - 1]);

    // find lowest of right (not in l3)
    if (i < l1)
      lor = n1[i];
    if (j < l2)
      lor = min(lor, n2[j]);

    return (l1 + l2) % 2 == 0 ? (hol + lor) / 2. : lor;
  }
};
