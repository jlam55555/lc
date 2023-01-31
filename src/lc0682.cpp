class Solution {
public:
  int calPoints(const vector<string> &operations) {
    std::stack<int> res;

    for (const auto &op : operations) {
      switch (op[0]) {
      case '+': {
        auto sc1{res.top()};
        res.pop();
        auto sc2{res.top()};
        res.push(sc1);
        res.push(sc1 + sc2);
        break;
      }
      case 'D':
        res.push(res.top() * 2);
        break;
      case 'C':
        res.pop();
        break;
      default:
        res.push(std::stoi(op));
      }
    }

    auto sum{0};
    while (!res.empty()) {
      sum += res.top();
      res.pop();
    }
    return sum;
  }
};
