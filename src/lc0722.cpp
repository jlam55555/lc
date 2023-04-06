// Fun little data structures problem.
// Of course we could do much more tersely with regular
// expressions (like @StefanPochmann does), but this was more fun.
class Solution {
  // The cursor marks the position that is about to be read.
  class Cursor {
    const std::vector<std::string> &source_;
    const int lines_;

  public:
    // Public for convenience, although these can be hidden
    // behind some accessors.
    int row{}, col{};

    // Getter functions.
    Cursor(std::vector<std::string> &source)
        : source_{source}, lines_(source_.size()) {}
    bool eol() const { return col == row_len(); }
    bool eof() const { return row == lines_ - 1 && eol(); }
    char at() const { return source_[row][col]; }
    int row_len() const { return source_[row].length(); }

    // Check for the digram at the current position, with error checking.
    bool digram(char a, char b) const {
      return col + 1 < row_len() && at() == a && source_[row][col + 1] == b;
    }

    // Operators.
    Cursor &operator++() {
      if (eol()) {
        ++row;
        col = 0;
      } else {
        ++col;
      }
      return *this;
    }
  };

public:
  vector<string> removeComments(vector<string> &source) {
    std::vector<std::string> res{{}};
    for (Cursor c{source}; !c.eof(); ++c) {
      if (c.eol()) {
        // Don't push empty lines.
        if (!res.back().empty()) {
          res.push_back({});
        }
      } else if (c.digram('/', '/')) {
        // Line comment. Discard until the end of this line.
        c.col = c.row_len() - 1;
      } else if (c.digram('/', '*')) {
        // Read block comment.
        ++++c;
        while (!c.digram('*', '/')) {
          ++c;
        }
        ++c;
      } else {
        // Copy character over.
        res.back().push_back(c.at());
      }
    }

    return res;
  }
};
