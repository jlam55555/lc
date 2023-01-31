class Solution {
public:
  //     // binary search
  //     int bs(int *a, int n, int t) {
  //         int l, r, m;
  //         for (l=0, r=n; l < r;) {
  //             m = (l+r)/2;
  //             if (a[m] < t) l=m+1;
  //             else r=m;
  //         }
  //         return l;
  //     }

  //     bool increasingTriplet(vector<int>& nums) {
  //         // increasing subsequence of length 3
  //         // patience sort can achieve this
  //         int dp[3] = {0};
  //         int size = 0;

  //         for (auto i : nums) {
  //             int pos = bs(dp, size, i);
  //             if (pos == size) {
  //                 if (++size == 3) {
  //                     return true;
  //                 }
  //             }
  //             dp[pos] = i;
  //         }

  //          return false;
  //     }

  // special-purpose patience sort for three
  bool increasingTriplet(vector<int> &nums) {
    int sm = INT_MAX, md = INT_MAX;
    for (auto i : nums) {
      if (i <= sm) {
        sm = i;
      } else if (i <= md) {
        md = i;
      } else {
        return true;
      }
    }
    return false;
  }
};
