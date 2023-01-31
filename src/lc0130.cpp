typedef vector<char> vc;
typedef vector<vc> vvc;

class Solution {
public:
  bool dfsDetect(vvc &b, int dim1, int dim2, int i, int j) {
    // reached an edge
    if (i < 0 || i >= dim1 || j < 0 || j >= dim2) {
      return true;
    }

    if (b[i][j] != 'O') {
      return false;
    }

    b[i][j] = 'D';
    bool isEdge = dfsDetect(b, dim1, dim2, i - 1, j) ||
                  dfsDetect(b, dim1, dim2, i + 1, j) ||
                  dfsDetect(b, dim1, dim2, i, j - 1) ||
                  dfsDetect(b, dim1, dim2, i, j + 1);

    return isEdge;
  }

  void dfsFill(vvc &b, int dim1, int dim2, int i, int j, char c) {
    if (i < 0 || i >= dim1 || j < 0 || j >= dim2 || b[i][j] == 'X' ||
        b[i][j] == c) {
      return;
    }

    b[i][j] = c;
    dfsFill(b, dim1, dim2, i - 1, j, c);
    dfsFill(b, dim1, dim2, i + 1, j, c);
    dfsFill(b, dim1, dim2, i, j - 1, c);
    dfsFill(b, dim1, dim2, i, j + 1, c);
  }

  void solve(vvc &board) {
    int dim1 = board.size(), dim2 = board[0].size();

    for (int i = 0; i < dim1; ++i) {
      for (int j = 0; j < dim2; ++j) {
        if (board[i][j] == 'O') {
          bool isEdge = dfsDetect(board, dim1, dim2, i, j);
          dfsFill(board, dim1, dim2, i, j, isEdge ? 'O' : 'X');
        }
      }
    }
  }
};
