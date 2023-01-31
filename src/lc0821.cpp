class Solution {
public:
  vector<int> shortestToChar(string s, char c) {
    auto prev{-1}, next{0};
    std::vector<int> res(s.length(), INT_MAX);

    // Set up next
    while (next < s.length() && s[next] != c) {
      ++next;
    }

    for (auto i{0}; i < s.length(); ++i) {
      // Update the next
      if (s[i] == c) {
        prev = i;
        ++next;
        while (next < s.length() && s[next] != c) {
          ++next;
        }
      }

      // Set the result array.
      if (next < s.length()) {
        res[i] = next - i;
      }
      if (prev >= 0) {
        res[i] = std::min(res[i], i - prev);
      }
    }
    return res;
  }
};
