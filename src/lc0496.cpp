class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    ::stack<int> runs; // store indices
    unordered_map<int, int> indexMap;
    vector<int> res(nums1.size(), -1);

    for (int i : nums2) {
      while (!runs.empty() && i > runs.top()) {
        indexMap[runs.top()] = i + 1;
        runs.pop();
      }
      runs.push(i);
    }

    for (int i = 0; i < nums1.size(); ++i)
      res[i] = indexMap[nums1[i]] - 1;

    return res;
  }
};
