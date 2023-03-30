// Lots of downvotes on this question. I guess that's because
// this is basically a medium-difficulty but somewhat tedious question.
class Solution {
public:
  int ComputeSpaces(int num_spaces, int num_breaks, int i) {
    auto d{std::div(num_spaces, num_breaks)};
    return d.quot + (i < d.rem);
  }

  std::string JustifyLine(const std::vector<std::string> &words, int width,
                          int i, int j, int spaces, bool last_line) {
    std::string res;

    // Single-word line or last line. Left-justify (right-pad).
    if (j - i == 1 || last_line) {
      for (; i < j; ++i) {
        res += words[i];
        res.push_back(' ');
      }
      res.pop_back();
      res += std::string(width - res.length(), ' ');
      return res;
    }

    // Multi-word line (that's not the last line). Divide
    // spaces spaces evenly over (j-i-1) word breaks.
    for (int breaks{j - i - 1}, k{i}; k < j - 1; ++k) {
      res += words[k];
      res += std::string(ComputeSpaces(spaces, breaks, k - i), ' ');
    }
    res += words[j - 1];
    return res;
  }

  vector<string> fullJustify(vector<string> &words, int width) {
    int n(words.size());
    std::vector<std::string> res;
    for (int i{}; i < n;) {
      // Find the next line of words.
      int j{i}, line_length{}, spaces{width};
      while (j < n && line_length + words[j].length() <= width) {
        line_length += words[j].length() + 1;
        spaces -= words[j].length();
        ++j;
      }
      --line_length;
      res.push_back(JustifyLine(words, width, i, j, spaces, j == n));
      i = j;
    }
    return res;
  }
};
