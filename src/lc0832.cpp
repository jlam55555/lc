class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
    // Can do this in one step, but I'm lazy.

    // Flip the image horizontally.
    auto h{image.size()}, w{image[0].size()};
    for (auto i{0}; i < h; ++i) {
      for (auto j{0}; j < w / 2; ++j) {
        std::swap(image[i][j], image[i][w - 1 - j]);
      }
    }

    // Invert the image.
    for (auto i{0}; i < h; ++i) {
      for (auto j{0}; j < w; ++j) {
        image[i][j] ^= 1;
      }
    }

    return image;
  }
};
