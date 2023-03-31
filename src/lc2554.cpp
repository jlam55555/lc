// Not sure why this is a medium question, feels like an easy question.
class Solution {
public:
  int maxCount(vector<int> &banned, int n, int max_sum) {
    // Sort banned so we can iterate over them efficiently.
    std::sort(banned.begin(), banned.end());
    int res{};
    for (int i{1}, j{}, m(banned.size()), sum{}; i <= n; ++i) {
      // This number is banned. Note that banned may have
      // duplicate elements, hence the loop.
      if (j < m && i == banned[j]) {
        while (j < m && i == banned[j]) {
          ++j;
        }
        continue;
      }

      // Number is not banned, add it to the sum.
      sum += i;

      // Sum exceeds max_sum, we're done.
      if (sum > max_sum) {
        break;
      }
      ++res;
    }
    return res;
  }
};
