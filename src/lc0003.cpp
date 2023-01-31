class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int last_seen[128] = {0};
    for (int i = 0; i < 128; ++i) {
      last_seen[i] = -1;
    }

    int longest_substr = 0;
    int substr_start = 0;
    for (int i = 0; i < s.length(); ++i) {
      substr_start = max(substr_start, last_seen[s[i]] + 1);

      int current_substr_length = i - substr_start + 1;
      longest_substr = max(longest_substr, current_substr_length);

      last_seen[s[i]] = i;
    }
    return longest_substr;
  }
};
