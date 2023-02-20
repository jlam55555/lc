class Solution {
public:
  int ToNum(std::string &s) {
    for (auto &c : s) {
      c -= 49; // 'a' - '0'
    }
    return std::stoi(s);
  }

  bool isSumEqual(std::string first, std::string second, std::string target) {
    return ToNum(first) + ToNum(second) == ToNum(target);
  }
};
