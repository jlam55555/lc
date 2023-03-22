// Idea: keep track of the sum of the lowest n-l jumps (where l =
// number of ladders and j = number of positive jumps). When this
// exceeds `bricks`, then we have to stop.
//
// We can use a priority queue to keep track of the highest l
// elements, and then keep track of the sum.
class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    int n(heights.size()), bricks_sum{};

    int i{};
    for (; i < n - 1; ++i) {
      // Don't have to jump.
      if (heights[i] >= heights[i + 1]) {
        continue;
      }

      // Maintain top l jumps.
      pq.push(heights[i + 1] - heights[i]);
      if (pq.size() > ladders) {
        if ((bricks_sum += pq.top()) > bricks) {
          break;
        }
        pq.pop();
      }
    }
    return i;
  }
};
