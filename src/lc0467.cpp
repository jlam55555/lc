class Solution {
public:
  // Returns true iff b is one letter ahead of a (including wraparound).
  // There are simpler ways to implement this but this is a very
  // literal implementation.
  bool ModDiff1(char a, char b) {
    return ((b - 'a') - (a - 'a') + 26) % 26 == 1;
  }

  // Get the length of the longest substring of s that begins
  // with the letter c.
  //
  // If c exists in the string, this will be the length from
  // the first occurrence of c to the end of the string.
  //
  // If c doesn't exist in the string, then return 0.
  int LongestSubstrStartsWith(char substr_start, int substr_len, char c) {
    return std::max(0,
                    substr_len - ((c - 'a') - (substr_start - 'a') + 26) % 26);
  }

  int findSubstringInWraproundString(string s) {
    // For each letter, store the maximum length sequential substring
    // beginning at this letter.
    std::array<int, 26> max_substr_len{};

    // Parse this substring, one contiguous substring at a time.
    for (int i{}, n(s.length()); i < n;) {
      // Get sequential substring.
      int j{i + 1};
      while (j < n && ModDiff1(s[j - 1], s[j])) {
        ++j;
      }

      // Update maximum lengths of substrings starting at each letter.
      for (char c{'a'}; c <= 'z'; ++c) {
        max_substr_len[c - 'a'] = std::max(
            max_substr_len[c - 'a'], LongestSubstrStartsWith(s[i], j - i, c));
      }
      i = j;
    }

    // The length of the longest substring is the number of unique substrings
    // beginning with a character. Accumulate the sum to get the result
    // for the total number of substrings beginning at any character.
    return std::accumulate(max_substr_len.begin(), max_substr_len.end(), 0);
  }
};
