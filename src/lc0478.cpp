// This is really a math problem rather than a programming
// problem but it's fun either way.
class Solution {
  double r_, x_, y_;

public:
  Solution(double radius, double x_center, double y_center)
      : r_{radius}, x_{x_center}, y_{y_center} {}

  vector<double> randPoint() {
    // Randomly sample radius from the interval [0, r_].
    // Note that f(r) should be a PDF governed by the
    // relationship: k*f(r) = f(k*r), and f(0) = 0
    // (I.e., it is linear and has axis-intercepts of 0).
    // To find the slope, we simply need to find a constant
    // such that there is unit area under the PDF.
    //
    // Thus: f(r) = 2*r/r_^2
    // The CDF is F(r) = r^2/r_^2
    // F^-1(x) = r_ * sqrt(x)
    double radius{r_ * std::sqrt(double(std::rand()) / RAND_MAX)};

    // Randomly sample angle from U[0, 2*pi).
    double angle{double(std::rand()) * 2 * M_PI / RAND_MAX};

    return {
        x_ + radius * std::cos(angle),
        y_ + radius * std::sin(angle),
    };
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
