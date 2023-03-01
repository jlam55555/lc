class Solution {
public:
  // Helper function.
  std::vector<std::string> StrSplit(std::string_view s, char delim) {
    size_t prev{}, pos;
    std::vector<std::string> res;
    while ((pos = s.find(delim, prev)) != std::string::npos) {
      res.emplace_back(s.substr(prev, pos - prev));
      prev = pos + 1;
    }
    res.emplace_back(s.substr(prev));
    return res;
  }

  bool IsIPv4(std::string_view s) {
    auto split{StrSplit(s, '.')};
    return split.size() == 4 &&
           std::all_of(split.begin(), split.end(), [](auto &part) {
             int len(part.length());

             // Make sure right length.
             if (!len || len > 3) {
               return false;
             }

             // Make sure all digits.
             if (!std::isdigit(part[0]) ||
                 (len > 1 && !std::isdigit(part[1])) ||
                 (len > 2 && !std::isdigit(part[2]))) {
               return false;
             }

             // Make sure no leading zeros.
             if (len > 1 && part[0] == '0') {
               return false;
             }

             // Make sure in range [0, 256).
             if (part.length() == 3 && part > "255") {
               return false;
             }

             return true;
           });
  }

  bool IsIPv6(std::string_view s) {
    auto split{StrSplit(s, ':')};
    return split.size() == 8 &&
           std::all_of(split.begin(), split.end(), [](const auto &part) {
             int len(part.size());

             // Make sure right length.
             if (len < 1 || len > 4) {
               return false;
             }

             // Make sure all hexadecimal.
             for (auto c : part) {
               if (!std::isxdigit(c)) {
                 return false;
               }
             }

             return true;
           });
  }

  string validIPAddress(string queryIP) {
    if (IsIPv4(queryIP)) {
      return "IPv4";
    } else if (IsIPv6(queryIP)) {
      return "IPv6";
    }
    return "Neither";
  }
};
