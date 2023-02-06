class Solution {
  struct LogEntry {
    int fn;
    bool start;
    int ts;
    LogEntry(const std::string &serialized) {
      int i{1}, j(serialized.length() - 2);
      while (std::isdigit(serialized[i])) {
        ++i;
      }
      while (std::isdigit(serialized[j])) {
        --j;
      }
      fn = std::stoi(serialized.substr(0, i));
      ts = std::stoi(serialized.substr(j + 1));
      start = j - i == 6;
      // Make end times exclusive to simplify the math.
      if (!start) {
        ++ts;
      }
    }
  };

public:
  std::vector<int> exclusiveTime(int n, std::vector<std::string> &logs) {
    std::vector<int> running_times(n);
    std::stack<int> call_stk;
    int last_ts{};

    for (LogEntry entry : logs) {
      // Update running time of last running function. Note that
      // we're using [start, end) ranges rather than the given
      // [start, end] ranges to simplify the math.
      if (!call_stk.empty()) {
        running_times[call_stk.top()] += entry.ts - last_ts;
      }
      // Update the stack and previous timestamp.
      if (entry.start) {
        call_stk.push(entry.fn);
      } else {
        call_stk.pop();
      }
      last_ts = entry.ts;
    }

    return running_times;
  }
};
