class Solution {
public:
  bool isPathCrossing(string path) {
    std::unordered_set<int> past;

    auto x{0}, y{0};
    past.insert(0);
    for (auto c : path) {
      switch (c) {
      case 'N':
        --y;
        break;
      case 'S':
        ++y;
        break;
      case 'E':
        ++x;
        break;
      case 'W':
        --x;
        break;
      }
      auto pos_hash{x * 10'000 + y};
      if (past.count(pos_hash)) {
        return true;
      }
      past.insert(pos_hash);
    }
    return false;
  }
};
