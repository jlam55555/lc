class Solution {
public:
  int Time(std::string ts) {
    int h{10 * (ts[0] - '0') + (ts[1] - '0')},
        m{10 * (ts[3] - '0') + (ts[4] - '0')};
    return 60 * h + m;
  }

  // Overlap computation similar to lc2409.cpp
  bool haveConflict(vector<string> &event1, vector<string> &event2) {
    int e1s{Time(event1[0])}, e1e{Time(event1[1])}, e2s{Time(event2[0])},
        e2e{Time(event2[1])};

    // Check if any overlap.
    return std::min(e1e, e2e) - std::max(e1s, e2s) >= 0;
  }
};
