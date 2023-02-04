/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
  struct ParseResult {
    // `pos` is the position after parsing a NestedInteger.
    int pos;
    NestedInteger res;
  };

  // I think I've been writing too many compilers. I feel like I've
  // done this problem a dozen times. This isn't the most efficient
  // or shortest solution (you could do better with a simple stack
  // for this problem) but this is a simple and straightforward solution.
  ParseResult deserialize(std::string_view s, int i) {
    // Integer.
    if (std::isdigit(s[i]) || s[i] == '-') {
      int j{i + 1};
      while (j < s.length() && std::isdigit(s[j])) {
        ++j;
      }
      return ParseResult{
          j,
          NestedInteger{std::stoi(std::string{s.substr(i, j)})},
      };
    }
    // Nested list.
    ++i;
    NestedInteger res;
    while (s[i] != ']') {
      auto [pos, nested] = deserialize(s, i);
      res.add(nested);
      i = pos;
      if (s[pos] == ']') {
        break;
      }
      // Skip the comma.
      ++i;
    }
    // Skip the end bracket.
    return {i + 1, res};
  }

public:
  NestedInteger deserialize(string s) { return deserialize(s, 0).res; }
};
