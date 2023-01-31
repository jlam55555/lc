class Solution {
public:
  struct transaction {
    string name;
    int minutes;
    int amount;
    string city;
    string original;
    bool operator<(const transaction &t2) { return minutes < t2.minutes; }
    bool too_far(const transaction &t2) {
      return abs(minutes - t2.minutes) > 60;
    }
    bool check_inv(const transaction &t2) {
      return !too_far(t2) && name == t2.name && city != t2.city;
    }
  };

  vector<string> str_split(string &s, char delim) {
    int pos, prev = 0;
    vector<string> res{};
    while ((pos = s.find(delim, prev)) != -1) {
      cerr << prev << " " << pos << endl;
      res.push_back(s.substr(prev, pos - prev));
      prev = pos + 1;
    }
    res.push_back(s.substr(prev, pos - prev));
    return res;
  }

  vector<string> invalidTransactions(vector<string> &transactions) {

    // lookup table: hour, city -> index[]
    unordered_map<int, unordered_map<string, vector<int>>> table{};

    vector<transaction> ts{};

    for (auto transaction : transactions) {
      auto words = str_split(transaction, ',');
      ts.push_back({
          words[0],
          atoi(words[1].c_str()),
          atoi(words[2].c_str()),
          words[3],
          transaction,
      });
    }

    sort(ts.begin(), ts.end());

    vector<string> res{};
    for (int i = 0; i < ts.size(); ++i) {
      // check if the transaction is invalid
      if (ts[i].amount > 1000) {
        res.push_back(ts[i].original);
        continue;
      }

      // check if invalid using surrounding transactions
      for (int j = i - 1; j >= 0; --j) {
        if (ts[i].too_far(ts[j])) {
          break;
        }
        if (ts[i].check_inv(ts[j])) {
          res.push_back(ts[i].original);
          goto cont;
        }
      }
      for (int j = i + 1; j < ts.size(); ++j) {
        if (ts[i].too_far(ts[j])) {
          break;
        }
        if (ts[i].check_inv(ts[j])) {
          res.push_back(ts[i].original);
          goto cont;
        }
      }
    cont:;
    }

    return res;
  }
};
