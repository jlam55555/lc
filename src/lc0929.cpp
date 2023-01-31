class Solution {
public:
  int numUniqueEmails(vector<string> &emails) {
    std::unordered_set<std::string> uniq;
    for (const auto &email : emails) {
      std::string res;
      auto i{0};
      while (email[i] != '@' && email[i] != '+') {
        if (email[i] == '.') {
          ++i;
          continue;
        }
        auto j{i + 1};
        while (email[j] != '.' && email[j] != '@' && email[j] != '+') {
          ++j;
        }
        res += email.substr(i, j - i);
        i = j;
      }
      while (email[i] != '@') {
        ++i;
      }
      res += email.substr(i);
      uniq.insert(res);
    }
    return uniq.size();
  }
};
