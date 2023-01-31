class Solution {
public:
  enum class Direction {
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3,
  };

  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    auto h{matrix.size()}, w{h ? matrix[0].size() : 0};
    std::vector<int> res{};
    res.reserve(h * w);
    Dfs(matrix, 0, 0, Direction::RIGHT, 0, 0, h, w, res);
    return res;
  }

  void Dfs(const std::vector<std::vector<int>> &m, int i, int j, Direction d,
           int t, int l, int b, int r, std::vector<int> &res) {

    // Reached the end.
    if (i < t || i >= b || j < l || j >= r) {
      return;
    }
    // Add next character.
    // std::cout << "i=" << i << " j=" << j << " d=" << int(d) << " t=" << t <<
    // " l=" << l << " b=" << b << " r=" << r << std::endl;
    res.push_back(m[i][j]);
    // Movement.
    switch (d) {
    case Direction::RIGHT:
      if (j + 1 >= r) {
        d = Direction::DOWN;
        ++i;
        ++t;
      } else {
        ++j;
      }
      break;
    case Direction::DOWN:
      if (i + 1 >= b) {
        d = Direction::LEFT;
        --j;
        --r;
      } else {
        ++i;
      }
      break;
    case Direction::LEFT:
      if (j - 1 < l) {
        d = Direction::UP;
        --i;
        --b;
      } else {
        --j;
      }
      break;
    case Direction::UP:
      if (i - 1 < t) {
        d = Direction::RIGHT;
        ++j;
        ++l;
      } else {
        --i;
      }
      break;
    }
    Dfs(m, i, j, d, t, l, b, r, res);
  }
};
