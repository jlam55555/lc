class Solution {
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    std::unordered_map<std::string, int> rev_ind{};
    for (auto i{0}; i < list1.size(); ++i) {
      rev_ind[list1[i]] = i;
    }

    // Find least index sum.
    auto least_index_sum{INT_MAX};
    std::vector<std::string> res;
    for (auto i{0}; i < list2.size(); ++i) {
      auto ind1{rev_ind.find(list2[i])};
      if (ind1 != rev_ind.end()) {
        auto index_sum{i + ind1->second};
        if (index_sum < least_index_sum) {
          least_index_sum = index_sum;
          res.clear();
          res.push_back(list2[i]);
        } else if (index_sum == least_index_sum) {
          res.push_back(list2[i]);
        }
      }
    }
    return res;
  }
};
