class Solution {
public:
  int lengthLongestPath(string input) {
    std::stack<int> stk;
    int cur_sum{}, res{}, i{}, N(input.length());
    while (i < N) {
      // Read a single line.
      int j{i};
      while (j < N && input[j] == '\t')
        ++j;
      int k{j};
      bool is_file{};
      while (k < N &&
             (std::isalnum(input[k]) || input[k] == ' ' || input[k] == '.')) {
        if (input[k] == '.') {
          is_file = true;
        }
        ++k;
      }

      int tabs = j - i;
      int component_len = k - j;

      while (stk.size() > tabs) {
        cur_sum -= stk.top();
        stk.pop();
      }

      // If directory, add it to the path.
      if (!is_file) {
        cur_sum += component_len;
        stk.push(component_len);
      }
      // If file, see if it is the longest path.
      else {
        res = std::max(res, cur_sum + component_len + int(stk.size()));
      }

      // Skip newline.
      i = k + 1;
    }
    return res;
  }
};
