typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
  vvi intervalIntersection(vvi &firstList, vvi &secondList) {

    int i = 0, j = 0;
    vvi res{};

    while (i != firstList.size() && j != secondList.size()) {
      // choose the interval that ends first
      int hi = min(firstList[i][1], secondList[j][1]);
      int lo = max(firstList[i][0], secondList[j][0]);

      // overlap
      if (lo <= hi) {
        res.push_back({lo, hi});
      }

      // remove first interval
      if (firstList[i][1] < secondList[j][1]) {
        ++i;
      } else {
        ++j;
      }
    }

    return res;
  }
};
