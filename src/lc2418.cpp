class Solution {
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    std::vector<std::pair<int, std::string>> people;
    int n(names.size());
    for (int i{}; i < n; ++i) {
      people.push_back({heights[i], names[i]});
    }
    std::sort(people.rbegin(), people.rend());
    for (int i{}; i < n; ++i) {
      names[i] = people[i].second;
    }
    return names;
  }
};
