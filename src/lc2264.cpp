class Solution {
public:
  string largestGoodInteger(string num) {
    char res{};
    for (int i{}; i < num.length();) {
      int j{i + 1};
      while (j < num.length() && num[j] == num[i]) {
        ++j;
      }
      if (j - i >= 3 && (!res || num[i] > res)) {
        res = num[i];
      }
      i = j;
    }
    return res ? std::string(3, res) : "";
  }
};
