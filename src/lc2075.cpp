class Solution {
public:
  string decodeCiphertext(string encodedText, int rows) {
    // go down each diagonal
    string s{};
    int cols = encodedText.length() / rows;

    for (int i = 0; i < cols; ++i) {
      // go down the diagonal: matrix[j][i+j]
      // thus i+j has to be < cols and j < rows
      for (int j = 0; j < rows && i + j < cols; ++j) {
        s += encodedText[j * cols + (i + j)];
      }
    }

    // find last space
    int i;
    for (i = s.length() - 1; i >= 0 && isspace(s[i]); --i)
      ;
    // i < 0 or !isspace(s[i])

    return s.substr(0, i + 1);
  }
};
