// Not sure why this isn't an easy question.
class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    int prev_row_count{}, res{};
    for (const auto &row : bank) {
      auto row_count{
          std::accumulate(row.begin(), row.end(), 0,
                          [](auto acc, auto c) { return acc + (c == '1'); })};

      if (!row_count) {
        continue;
      }
      if (prev_row_count) {
        res += row_count * prev_row_count;
      }
      prev_row_count = row_count;
    }
    return res;
  }
};
