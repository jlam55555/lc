class Solution {
public:
  const std::vector<std::string>
  findRelativeRanks(const std::vector<int> &score) {
    std::vector<int> sorted_scores(score.begin(), score.end());
    std::sort(sorted_scores.begin(), sorted_scores.end(), std::greater<>());
    std::unordered_map<int, int> lookup{};
    for (auto i{0}; i < sorted_scores.size(); ++i) {
      lookup[sorted_scores[i]] = i;
    }
    std::vector<string> res{};
    for (auto i : score) {
      auto pos{lookup[i]};
      switch (pos) {
      case 0:
        res.push_back("Gold Medal");
        break;
      case 1:
        res.push_back("Silver Medal");
        break;
      case 2:
        res.push_back("Bronze Medal");
        break;
      default:
        res.push_back(std::to_string(pos + 1));
        break;
      }
    }
    return res;
  }
};
