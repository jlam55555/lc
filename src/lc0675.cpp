// General idea: find the shortest path between the lowest number
// to the second-lowest number, and the shortest path from the
// second-lowest number to the third-lowest, and so on. The result
// is the sum of these paths.
//
// The problem of searching for the shortest path between two
// cells on a grid, where each cell is marked as being traversable
// or not, is called the maze/grid search problem.
//
// The basic solution is called Lee's algorithm, and uses a BFS.
// This can perhaps be optimized using a bidirectional BFS.
// I do a simple naive BFS (level-order traversal) in TryBfs().
// This doesn't TLE, but it is slow.
//
// An optimization with good empirical quality is called Hadlock's
// algorithm, which optimistically tries to find a path with the
// least number of deviations from the shortest path (Manhattan path).
//
// Simple implementations of both Lee's and Hadlock's algorithms
// are included here. The Hadlock's algorithm is heavily inspired
// by @StefanPochmann.
class Solution {
  using Board = std::vector<std::vector<int>>;

public:
  // BFS/level-order traversal used in naive solution.
  // This has the same interface as the Hadlock() algorithm below.
  int Lee(const Board &forest, const Board &sorted, int m, int n, int i1,
          int j1, int i2, int j2) {
    static bool seen[50][50];
    std::memset(seen, 0, sizeof(seen));

    // Level-order traversal. I use two stacks rather than a queue
    // because it has a better memory access pattern.
    std::stack<std::pair<int, int>> curr_depth, next_depth;
    curr_depth.push({i1, j1});
    int depth{};
    while (!curr_depth.empty()) {
      while (!curr_depth.empty()) {
        auto [i, j]{curr_depth.top()};
        curr_depth.pop();

        if (i == i2 && j == j2) {
          return depth;
        }

        if (!forest[i][j] || seen[i][j]) {
          continue;
        }
        seen[i][j] = true;

// Recurse.
#define add_cell_to_set(i, j)                                                  \
  if ((i) >= 0 && (i) < m && (j) >= 0 && (j) < n)                              \
    next_depth.push({(i), (j)});
        add_cell_to_set(i + 1, j);
        add_cell_to_set(i - 1, j);
        add_cell_to_set(i, j + 1);
        add_cell_to_set(i, j - 1);
#undef add_cell_to_set
      }
      ++depth;
      std::swap(curr_depth, next_depth);
    }
    return -1;
  }

  // Find the shortest distance beteen (i1, j1) and (i2, j2) in a grid where
  // each cell is either traversable or not. This has the same interface
  // as the Lee() algorithm above.
  int Hadlock(Board &forest, Board &sorted, int m, int n, int i1, int j1,
              int i2, int j2) {
    // Slight optimization over reallocating a vector every time.
    static bool seen[50][50];
    std::memset(seen, 0, sizeof(seen));

    // Store the set of cells with the current and next number of detours.
    // stack/queue/vector doesn't really matter here. Just need to have
    // collections to store the current and next cell-sets. std::queue has a
    // worse memory access pattern (linked-list-like) than the other two, and
    // std::stack has a simpler interface than std::vector.
    std::stack<std::pair<int, int>> curr_detours, next_detours;

    // Hadlock search.
    int manhattan_dist{std::abs(i1 - i2) + std::abs(j1 - j2)};
    curr_detours.push({i1, j1});
    for (int detours{}; !curr_detours.empty(); ++detours) {
      while (!curr_detours.empty()) {
        auto [i, j]{curr_detours.top()};
        curr_detours.pop();

        if (i == i2 && j == j2) {
          return manhattan_dist + 2 * detours;
        }

        if (!forest[i][j] || seen[i][j]) {
          continue;
        }
        seen[i][j] = true;

// The `closer` trick borrowed from @StefanPochmann, along
// with a bounds-check.
#define add_cell_to_set(i, j, closer)                                          \
  if ((i) >= 0 && (i) < m && (j) >= 0 && (j) < n)                              \
    ((closer) ? curr_detours : next_detours).push({(i), (j)});
        add_cell_to_set(i + 1, j, i < i2);
        add_cell_to_set(i - 1, j, i > i2);
        add_cell_to_set(i, j + 1, j < j2);
        add_cell_to_set(i, j - 1, j > j2);
#undef add_cell_to_set
      }
      std::swap(curr_detours, next_detours);
    }
    return -1;
  }

  int cutOffTree(Board &forest) {
    int m(forest.size()), n(forest[0].size());

    // Get all tiles in sorted order.
    Board sorted;
    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        if (forest[i][j] > 1) {
          sorted.push_back({forest[i][j], i, j});
        }
      }
    }
    sorted.push_back({0, 0, 0});
    std::sort(sorted.begin(), sorted.end());

    // Try to traverse from each square to the next.
    int res{};
    for (int i{}, len(sorted.size()); i < len - 1; ++i) {
      // Try switching Hadlock() for Lee() to see the performance difference.
      auto steps{Hadlock(forest, sorted, m, n, sorted[i][1], sorted[i][2],
                         sorted[i + 1][1], sorted[i + 1][2])};
      if (steps < 0) {
        return steps;
      }
      res += steps;
    }
    return res;
  }
};
