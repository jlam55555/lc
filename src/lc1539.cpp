class Solution {
public:
  // We can find this using a binary search.
  //
  // If `arr[i] == i+1`, then we know that no
  // elements before it have been missing. If
  // `arr[i] == i+2`, then we know that one element
  // before it was missing, and so on and so forth.
  //
  //   i 0 1 2 3 4 5 6
  // arr 1 2 3 4 6 7 9
  //           ^ no elements missing until here
  //             ^ notice: one element missing!
  //
  // Thus, we want to find the first element such
  // that `arr[i] >= i+k+1`. The answer then is `i+1`.
  // How we derive the answer:
  //
  // k = 1
  //   i 0 1 2 3
  // arr 1 2 5 6
  //         ^ arr[i] >= i+k (5 > 3)
  //
  // previous missing int   how much we went over k
  //          |                |
  //          v                v
  // answer = arr[i]-1 - ((arr[i]-i-1) - k)
  //        = i + k
  //        = 2 + 1 = 3
  int findKthPositive(vector<int> &arr, int k) {
    // Sentinel node.
    int l{}, r(arr.size());
    while (l < r) {
      int m{(l + r) >> 1};
      if (arr[m] >= m + k + 1) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l + k;
  }
};
