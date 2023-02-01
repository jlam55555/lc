using ll = long long;

class Solution {
public:
  // General idea:
  // - Given a value of nums2[i], we want to find the sum
  //   of nums1[i] + (the largest (k-1) elements of nums1[j]
  //   corresponding to elements of nums2 where nums2[j] > nums2[i]).
  //   And then we multiply this by nums2[i].
  // - To do this, we iterate _down_ nums2 and keep track of
  //   the top k (or k-1, it doesn't matter) values of nums1
  //   that we've seen so far. We use a priority queue to do this.
  ll maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    // Sort (nums1[i], nums2[i]) pairs by num2 value.
    int n = nums1.size();
    std::vector<std::pair<int, int>> pairs{};
    for (int i{}; i < n; ++i) {
      pairs.push_back(std::make_pair(nums2[i], nums1[i]));
    }

    // Sort lexicographically, largest to smallest.
    // (I.e., sort by nums2[i] descending.)
    std::sort(pairs.rbegin(), pairs.rend());

    // Keep track of the largest k elements from nums1
    // at any given point.
    int i{};
    ll sum1{};
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq1;
    for (; i < k; ++i) {
      sum1 += pairs[i].second;
      pq1.push(pairs[i].second);
    }

    // Try to find a better result.
    auto res{sum1 * pairs[k - 1].first};
    for (; i < n; ++i) {
      // New candidate =
      //    (sum of top (k-1) elements + current element)
      //    * element of nums2
      res =
          std::max(res, (sum1 - pq1.top() + pairs[i].second) * pairs[i].first);

      // Update the top k elements and their sum.
      sum1 += std::max(0, pairs[i].second - pq1.top());
      pq1.push(pairs[i].second);
      pq1.pop();
    }
    return res;
  }
};
