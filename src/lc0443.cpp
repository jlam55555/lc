// Basically the same as lc0026.cpp: remove adjacent
// duplicate elements in-place.
class Solution {
public:
  int compress(vector<char> &chars) {
    int res{};
    for (int i{}, n(chars.size()); i < n;) {
      int j{i + 1};
      while (j < n && chars[i] == chars[j]) {
        ++j;
      }
      chars[res++] = chars[i];
      if (j - i > 1) {
        for (auto c : std::to_string(j - i)) {
          chars[res++] = c;
        }
      }
      i = j;
    }
    return res;
  }
};
