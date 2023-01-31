class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> res{};

    for (const auto &str : strs) {
      string strcpy = str;
      sort(strcpy.begin(), strcpy.end());
      res[strcpy].push_back(str);
    }

    vector<vector<string>> ans{};
    for (const auto &anagramSet : res) {
      ans.push_back(anagramSet.second);
    }

    return ans;
  }
};
