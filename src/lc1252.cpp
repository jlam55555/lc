class Solution {
public:
  int oddCells(int m, int n, vector<vector<int>> &indices) {
    std::vector<int> rows(m, 0);
    std::vector<int> cols(n, 0);
    for (const auto &v : indices) {
      rows[v[0]] ^= 1;
      cols[v[1]] ^= 1;
    }

    auto odr{0}, oc{0};
    for (auto r : rows) {
      odr += r;
    }
    for (auto c : cols) {
      oc += c;
    }

    // Need to count how many have odd row XOR odd col
    return m * n - odr * oc - (m - odr) * (n - oc);
  }
};
