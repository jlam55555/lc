class Solution {
public:
  int ParseTime(std::string &s) {
    return std::stoi(s.substr(0, 2)) * 60 + std::stoi(s.substr(3));
  }

  // Greedy algorithm.
  int convertTime(string current, string correct) {
    int t1{ParseTime(current)}, t2{ParseTime(correct)}, diff{t2 - t1}, res{};
    res += diff / 60;
    diff %= 60;
    res += diff / 15;
    diff %= 15;
    res += diff / 5;
    diff %= 5;
    return res + diff;
  }
};
