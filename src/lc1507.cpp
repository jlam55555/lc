class Solution {
public:
  std::vector<std::string> str_split(const std::string &s, char delimiter) {
    std::vector<std::string> res;
    size_t last = 0;
    size_t next = 0;
    while ((next = s.find(delimiter, last)) != string::npos) {
      res.push_back(s.substr(last, next - last));
      last = next + 1;
    }
    res.push_back(s.substr(last));
    return res;
  }

  std::string Day(const std::string &s) {
    auto i{0};
    while (std::isdigit(s[i]))
      ++i;
    return (i == 1 ? "0" : "") + s.substr(0, i);
  }

  std::string Month(const std::string &s) {
    static std::unordered_map<std::string, int> months{
        {"Jan", 1}, {"Feb", 2},  {"Mar", 3},  {"Apr", 4},
        {"May", 5}, {"Jun", 6},  {"Jul", 7},  {"Aug", 8},
        {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12},
    };
    auto res{months[s]};
    return (res < 10 ? "0" : "") + std::to_string(res);
  }

  string reformatDate(string date) {
    auto words{str_split(date, ' ')};

    std::string res;
    res += words[2];
    res.push_back('-');
    res += Month(words[1]);
    res.push_back('-');
    res += Day(words[0]);
    return res;
  }
};
