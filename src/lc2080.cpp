class RangeFreqQuery {
  unordered_map<int, vector<int>> ind{};

public:
  RangeFreqQuery(vector<int> &arr) {
    // map each value to its indices
    for (int i = 0; i < arr.size(); ++i) {
      ind[arr[i]].push_back(i);
    }
  }

  int query(int left, int right, int value) {
    // binary search left and right index of value
    // be careful of the inclusivities
    auto &vind = ind[value];

    // first index >= left
    auto it_left = lower_bound(vind.begin(), vind.end(), left);

    // first index > right
    // subtract one to get last index <= right
    auto it_right = upper_bound(vind.begin(), vind.end(), right);
    if (it_right == vind.begin()) {
      return 0;
      // throw logic_error{"it right is vind.begin()"};
    }
    --it_right;

    // cout << value << " " << (it_right-it_left) << " " << *it_left << " " <<
    // *it_right << endl;
    return (it_right - it_left) + 1;
  }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
