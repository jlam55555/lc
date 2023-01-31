class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    // find maximum length of subarray beginning at nums[i], nums[j]
    int dp[1001][1001] = {0};

    int maxLen = 0;

    // loop through each starting position of nums1
    for (int i = 0; i < nums1.size(); ++i) {

      // loop through each starting position of nums2
      for (int j = 0; j < nums2.size(); ++j) {

        if (nums1[i] == nums2[j]) {
          dp[i][j] = 1 + (i && j ? dp[i - 1][j - 1] : 0);
          maxLen = max(maxLen, dp[i][j]);
        }
      }
    }

    return maxLen;
  }
};
