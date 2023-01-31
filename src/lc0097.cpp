class Solution {
public:
  bool isInterleave(std::string_view s1, std::string_view s2,
                    std::string_view s3) {
    if (s1.length() + s2.length() != s3.length()) {
      return false;
    }
    std::vector<int> dp1(s2.length() + 1), dp2(s2.length() + 1);
    dp2[0] = true;
    for (int i{}; i <= s1.length(); ++i) {
      for (int j{}; j <= s2.length(); ++j) {
        if (i) {
          dp2[j] |= dp1[j] && s1[i - 1] == s3[i + j - 1];
        }
        if (j) {
          dp2[j] |= dp2[j - 1] && s2[j - 1] == s3[i + j - 1];
        }
      }
      std::swap(dp1, dp2);
      std::fill(dp2.begin(), dp2.end(), 0);
    }
    return dp1.back();
  }
};
