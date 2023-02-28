class Solution {
public:
  int ToDay(int m, int d) {
    static constexpr const int month_days[]{31, 28, 31, 30, 31, 30,
                                            31, 31, 30, 31, 30, 31};

    int res{};
    for (int i{}; i < m - 1; i++) {
      res += month_days[i];
    }
    return res + d - 1;
  }

  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    int am1{std::stoi(arriveAlice.substr(0, 2))},
        ad1{std::stoi(arriveAlice.substr(3))},
        am2{std::stoi(leaveAlice.substr(0, 2))},
        ad2{std::stoi(leaveAlice.substr(3))},
        bm1{std::stoi(arriveBob.substr(0, 2))},
        bd1{std::stoi(arriveBob.substr(3))},
        bm2{std::stoi(leaveBob.substr(0, 2))},
        bd2{std::stoi(leaveBob.substr(3))};

    // Translate dates into days of the year.
    int a1{ToDay(am1, ad1)}, a2{ToDay(am2, ad2)}, b1{ToDay(bm1, bd1)},
        b2{ToDay(bm2, bd2)};

    // Compute overlap of two intervals.
    int overlap_start{std::max(a1, b1)}, overlap_end{std::min(a2, b2)};
    return std::max(0, overlap_end - overlap_start + 1);
  }
};
