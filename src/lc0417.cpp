// I'm fairly surprised at myself: this worked on the first try!
// I even wrote debugging methods but didn't have to use them because
// there weren't any errors.
//
// I guess the most difficult thing here was how to deal with
// backtracking when two adjacent cells have the same height.
// I basically had to introduce the idea of "uncertainty" so that
// if a cell doesn't find a solution but may have the possibility
// of finding a solution by going through the previous path, then it
// would say that it cannot continue but remain unsure until the end.
//
// Ah, now that I look at the top solution I realize that this is not
// the easiest way to think about this at all. If you invert the problem
// and flood-fill from the ocean, this is a much easier problem. This
// solution works nonetheless and the memoization makes it decently fast.
class Solution {
  using Board = std::vector<std::vector<int>>;

  enum class Result {
    UNSURE,
    ON_PATH,
    YES,
    NO,
  };
  using ResultBoard = std::vector<std::vector<Result>>;

  // The tricky thing with this DFS is that we want to record all intermediate
  // results, and we cannot backtrack.
  //
  // Each square of the grid has four designations:
  // - -2: Not sure and on the current path.
  // - -1: Not sure.
  // - 0: Definitely cannot reach the ocean.
  // - 1: Definitely can reach the ocean.
  Result Dfs(const Board &heights, int m, int n, ResultBoard &res, int i, int j,
             int val) {
    // Off the edge of the board or water can't flow this way.
    if (i < 0 || i >= m || j < 0 || j >= n || heights[i][j] > val) {
      return Result::NO;
    }

    // Already know the answer for this spot, or it is already on the
    // current path.
    if (res[i][j] != Result::UNSURE) {
      return res[i][j];
    }

    // Mark the current square as on the current path.
    res[i][j] = Result::ON_PATH;

    // Recurse.
    auto v{heights[i][j]};
    auto up{Dfs(heights, m, n, res, i - 1, j, v)};
    auto down{Dfs(heights, m, n, res, i + 1, j, v)};
    auto left{Dfs(heights, m, n, res, i, j - 1, v)};
    auto right{Dfs(heights, m, n, res, i, j + 1, v)};

    Result ans{(up == Result::YES || down == Result::YES ||
                left == Result::YES || right == Result::YES)
                   ? Result::YES
                   : Result::NO};

    // If any neighbors were on the path and we cannot
    // find a way, then list this as unsure.
    if (ans == Result::NO &&
        (up == Result::ON_PATH || down == Result::ON_PATH ||
         left == Result::ON_PATH || right == Result::ON_PATH)) {
      res[i][j] = Result::UNSURE;
      return ans;
    } else {
      return res[i][j] = ans;
    }
  }

  // For debugging.
  // void Print(ResultBoard& b) {
  //     for (const auto& row : b) {
  //         for (auto v : row) {
  //             std::cout << v << " ";
  //         }
  //         std::cout << std::endl;
  //     }
  //     std::cout << std::endl;
  // }

public:
  // General idea: do a DFS from every spot to both the Pacific
  // and Atlantic oceans (to the edges of the board).
  Board pacificAtlantic(Board &heights) {
    int m(heights.size()), n(heights[0].size());

    // Set up boards for Pacific and Atlantic.
    ResultBoard pacific(m, std::vector<Result>(n, Result::UNSURE)),
        atlantic{pacific};
    for (int i{}; i < m; ++i) {
      pacific[i][0] = Result::YES;
      atlantic[i][n - 1] = Result::YES;
    }
    for (int j{}; j < n; ++j) {
      pacific[0][j] = Result::YES;
      atlantic[m - 1][j] = Result::YES;
    }

    // Check which cells can reach the Atlantic/Pacific ocean.
    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        Dfs(heights, m, n, atlantic, i, j, INT_MAX);
        Dfs(heights, m, n, pacific, i, j, INT_MAX);
      }
    }

    // For debugging.
    // Print(atlantic);
    // Print(pacific);

    // Return the list of cells which can reach both the
    // Pacific and the Atlantic ocean;
    Board res;
    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        if (pacific[i][j] == Result::YES && atlantic[i][j] == Result::YES) {
          res.push_back({i, j});
        }
      }
    }

    return res;
  }
};
