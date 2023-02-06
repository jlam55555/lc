class Solution {
public:
  string reformatNumber(string number) {
    std::string res;

    for (int i{}; i < number.size(); ++i) {
      if (std::isdigit(number[i])) {
        res.push_back(number[i]);
        if (!res.empty() && res.length() % 4 == 3) {
          res.push_back('-');
        }
      }
    }

    // Fix the last group.
    switch (res.length() % 4) {
    case 0:
      // Perfectly divisible by three, remove last dash.
      res.pop_back();
      break;
    case 1:
      // Last group is a group of four, move the dash forwards.
      std::swap(res[res.length() - 2], res[res.length() - 3]);
      break;
    case 2:
      // Last group is a group of two, nothing to do here.
      break;
    case 3:
      // Shouldn't happen. If the last group is a group of
      // three, a dash should have been added after it.
      throw logic_error{"shouldn't happen"};
    }
    return res;
  }
};
