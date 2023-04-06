// Idea: do it from the left and from the
// right, separately.
//
// From the left: assume you are looking for the number
// of moves to move all balls left of boxes[i] to boxes[i].
// If it takes res[i-1] moves to get all boxes to
// boxes[i-1], and there are m boxes in boxes[0:i], then
// res[i] = res[i-1] + m.
//
// Then repeat from the right. We can combine the left
// and right computations into one pass, but I leave it
// separated here for clarity.
class Solution {
public:
  vector<int> minOperations(string boxes) {
    int n(boxes.length());
    std::vector<int> left(n), right(n);

    // Compute from left.
    for (int i{}, count{}; i < n; ++i) {
      if (i) {
        left[i] = left[i - 1] + count;
      }
      count += boxes[i] == '1';
    }

    // Compute from right;
    for (int i{n - 1}, count{}; i >= 0; --i) {
      if (i < n - 1) {
        right[i] = right[i + 1] + count;
      }
      count += boxes[i] == '1';
    }

    // Aggregate.
    for (int i{}; i < n; ++i) {
      left[i] += right[i];
    }
    return left;
  }
};
