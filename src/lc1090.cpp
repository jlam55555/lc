class Solution {
public:
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int numWanted, int useLimit) {
    // greedy approach: keep selecting the largest values, unless
    // it has already been seen useLimit times

    vector<vector<int>> valuesLabels{};
    for (int i = 0; i < labels.size(); ++i) {
      valuesLabels.push_back({values[i], labels[i]});
    }

    sort(valuesLabels.rbegin(), valuesLabels.rend());

    unordered_map<int, int> seen{};
    int count = 0, sum = 0, i = 0;
    while (count < numWanted) {
      int nextNum, nextInd;
      do {
        if (i == valuesLabels.size()) {
          goto end;
        }
        auto t = valuesLabels[i++];
        nextNum = t[0];
        nextInd = t[1];
      } while (++seen[nextInd] > useLimit);
      ++count;
      sum += nextNum;
    }

  end:
    return sum;
  }
};
