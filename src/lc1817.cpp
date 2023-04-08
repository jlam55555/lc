// Not sure why this is a medium question.
class Solution {
public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
    std::unordered_map<int, std::unordered_set<int>> users;
    for (const auto &log : logs) {
      users[log[0]].insert(log[1]);
    }

    std::vector<int> res(k);
    for (const auto &[user, times] : users) {
      ++res[times.size() - 1];
    }
    return res;
  }
};
