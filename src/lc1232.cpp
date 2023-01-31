class Solution {

public:
  std::tuple<int, int> GetNormal(int x0, int y0, int x1, int y1) {

    return std::make_tuple(-(y1 - y0), x1 - x0);
  }

  bool Parallel(std::tuple<int, int> v1, std::tuple<int, int> v2) {

    const auto [x1, y1] = v1;

    const auto [x2, y2] = v2;

    return x1 * y2 - x2 * y1 == 0;
  }

  void PrintV(std::tuple<int, int> v) {

    const auto [x, y] = v;

    std::cout << "(" << x << ", " << y << ")" << std::endl;
  }

  bool checkStraightLine(vector<vector<int>> &coordinates) {

    // Get the orthogonal vector.

    auto x0{coordinates[0][0]}, y0{coordinates[0][1]};

    auto normal = GetNormal(x0, y0, coordinates[1][0], coordinates[1][1]);

    for (auto i{2}; i < coordinates.size(); ++i) {

      auto normal2 = GetNormal(x0, y0, coordinates[i][0], coordinates[i][1]);

      if (!Parallel(normal2, normal)) {

        return false;
      }
    }

    return true;
  }
};
