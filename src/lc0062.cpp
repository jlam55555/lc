class Solution {
public:
  // memoization
  int found[101][101] = {0};

  int uniquePaths(int m, int n) {
    if (m == 1 || n == 1) {
      return 1;
    }

    int tmp[] = {min(m, n), max(m, n)};

    if (found[tmp[0]][tmp[1]]) {
      return found[tmp[0]][tmp[1]];
    }

    return found[tmp[0]][tmp[1]] =
               uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
  }
};
