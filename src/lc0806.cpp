class Solution {
public:
  vector<int> numberOfLines(const vector<int> &widths, const string_view s) {
    auto line_width{0};
    auto num_lines{1};
    for (auto c : s) {
      if ((line_width += widths[c - 'a']) > 100) {
        line_width = widths[c - 'a'];
        ++num_lines;
      }
    }
    return {num_lines, line_width};
  }
};
