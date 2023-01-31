class Solution {
public:
  int distributeCandies(vector<int> &candyType) {
    unordered_set<int> seen{};

    int count = 0;
    for (int type : candyType) {
      if (!seen.count(type)) {
        ++count;
        seen.insert(type);
      }
    }

    return min((int)candyType.size() / 2, count);
  }
};
