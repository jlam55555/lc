class Solution {
public:
  int maxSum(vector<int> &nums1, vector<int> &nums2) {
    int n1i = nums1.size() - 1, n2i = nums2.size() - 1;
    long n1s = 0, n2s = 0;

    while (1) {
      // find next equal number
      while (n1i >= 0 && n2i >= 0 && nums1[n1i] != nums2[n2i]) {
        while (n1i >= 0 && nums1[n1i] > nums2[n2i])
          n1s += nums1[n1i--];
        while (n2i >= 0 && n1i >= 0 && nums2[n2i] > nums1[n1i])
          n2s += nums2[n2i--];
      }

      // now n1i == n2i or one of them is at 0
      if (n1i < 0 || n2i < 0) {
        while (n2i >= 0)
          n2s += nums2[n2i--];
        while (n1i >= 0)
          n1s += nums1[n1i--];
        return max(n1s, n2s) % 1000000007;
      }

      n1s = n2s = nums1[n1i] + max(n1s, n2s);
      n1i--;
      n2i--;
    }
  }
};
