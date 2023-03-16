// If we want to uniformly sample these, then we should
// randomly pick a rectangle with a probability proportional
// to the ratio of its area to the total area, then
// uniformly sample within it.
//
// Thus we generate a CDF "curve" (sorted array), randomly pick
// a rectangle using the inverse CDF curve (binary search),
// and then uniformly sample within the rectangle based on that.
class Solution {
  struct Rect {
    int x, y, w, h;
    // Note the +1 in the width and height, since we're doing discrete
    // sampling.
    Rect(int x, int y, int a, int b) : x{x}, y{y}, w{a - x + 1}, h{b - y + 1} {}
    std::vector<int> Pick() {
      return {
          x + std::rand() % w,
          y + std::rand() % h,
      };
    }
  };
  std::vector<Rect> rs_;
  std::vector<int> areas_;
  int total_area_{};

public:
  Solution(vector<vector<int>> &rects) {
    for (const auto &rect : rects) {
      rs_.emplace_back(rect[0], rect[1], rect[2], rect[3]);
      areas_.emplace_back(total_area_ += rs_.back().w * rs_.back().h);
    }
  }

  vector<int> pick() {
    int search(std::ceil(double(std::rand()) * total_area_ / RAND_MAX));
    auto it{std::lower_bound(areas_.begin(), areas_.end(), search)};
    auto i{std::distance(areas_.begin(), it)};
    return rs_[i].Pick();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
