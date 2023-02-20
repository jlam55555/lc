class Solution {
public:
  string capitalizeTitle(string title) {
    for (int i{}, n(title.length()); i < n; ++i) {
      int j{i + 1};
      while (j < n && title[j] != ' ') {
        ++j;
      }

      for (int k{i}; k < j; ++k) {
        title[k] |= 0x20;
      }

      if (j - i > 2) {
        title[i] &= ~0x20;
      }

      i = j;
    }
    return title;
  }
};
