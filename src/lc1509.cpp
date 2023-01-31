class Solution {
public:
  int minDifference(vector<int> &nums) {

    // if four elements or less, we can make the range 0 in three moves
    if (nums.size() <= 4) {
      return 0;
    }

    // get min and max four elements
    priority_queue<int, vector<int>, greater<int>> smol(nums.begin(),
                                                        nums.end());
    priority_queue<int, vector<int>, less<int>> lorg(nums.begin(), nums.end());

    int smallest[4], largest[4];
    for (int i = 0; i < 4; ++i) {
      smallest[i] = smol.top();
      smol.pop();

      largest[i] = lorg.top();
      lorg.pop();
    }

    // find smallest range
    // can make range largest[3]-smallest[0], largest[2]-smallest[1], ...
    int smallestRange = INT_MAX;
    for (int i = 0; i < 4; ++i) {
      smallestRange = min(smallestRange, largest[3 - i] - smallest[i]);
    }

    return smallestRange;
  }
};
