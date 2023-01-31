class Solution {
  //     struct point {
  //         vector<int> vec;
  //         int dist;
  //     };

  //     // returns whether first < second (in maxheap, so this is flipped)
  //     static bool cmpFn(struct point &a, struct point &b) {
  //         return a.dist > b.dist;
  //     }
public:
  int dist(vector<int> &point) {
    return point[0] * point[0] + point[1] * point[1];
  }

  int partition(vector<vector<int>> &arr, int left, int right) {
    int originalLeft = left, pivot = dist(arr[left]);
    ++left;

    while (1) {
      while (left < right && dist(arr[left]) < pivot)
        ++left;
      while (left <= right && dist(arr[right]) > pivot)
        --right;
      if (left >= right)
        break;
      swap(arr[left], arr[right]);
      ++left;
      --right;
    }
    swap(arr[originalLeft], arr[right]);
    return right;
  }

  void quickselect(vector<vector<int>> &arr, int left, int right, int n) {
    if (left >= right)
      return;
    int pivot = ::rand() % (right - left) + left;
    ::swap(arr[left], arr[pivot]);

    int mid = partition(arr, left, right);
    int leftLength = mid - left + 1;
    if (n < leftLength)
      quickselect(arr, left, mid - 1, n);
    else if (n > leftLength)
      quickselect(arr, mid + 1, right, n - leftLength);
  }

  // quickselect
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    vector<vector<int>> res(K);
    quickselect(points, 0, points.size() - 1, K);

    for (int i = 0; i < K; ++i) {
      res[i] = ::move(points[i]);
    }

    return res;
  }

  //     // minHeap
  //     vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
  //         int len = points.size(), i;
  //         vector<struct point> pointsHeap;
  //         vector<vector<int>> res(K);

  //         for (i = 0; i < len; ++i)
  //             pointsHeap.push_back({
  //                 .vec = points[i],
  //                 .dist = points[i][0]*points[i][0] +
  //                 points[i][1]*points[i][1]
  //             });
  //         ::make_heap(pointsHeap.begin(), pointsHeap.end(), cmpFn);

  //         for (i = 0; i < K; ++i) {
  //             res[i] = pointsHeap.front().vec;
  //             ::pop_heap(pointsHeap.begin(), pointsHeap.end(), cmpFn);
  //             pointsHeap.pop_back();
  //         }

  //         return res;
  //     }
};
