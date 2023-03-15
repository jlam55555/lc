class Solution {
public:
  int splitNum(int num) {
    auto num_str{std::to_string(num)};
    std::sort(num_str.begin(), num_str.end());

    std::string num1_str, num2_str;
    for (int i{}, n(num_str.length()); i < n; i += 2) {
      num1_str.push_back(num_str[i]);
      if (i + 1 < n) {
        num2_str.push_back(num_str[i + 1]);
      }
    }

    return std::stoi(num1_str) + std::stoi(num2_str);
  }
};
