#define MAX 1000000007

class Solution {
public:
  int numDecodings(::string s) {
    int prev, curr, next, i;

    for (prev = 1, curr = 0, next = 0, i = 0; i < s.length(); ++i) {
      // if current character is *
      if (s[i] == '*') {
        // multiply current position by 9
        curr = (curr + prev * 9) % MAX;

        // if two letters
        if (i < s.length() - 1) {
          // if next letter is known
          if (s[i + 1] != '*') {
            // pretend like it's 1
            next = (next + prev) % MAX;

            // pretend like it's two
            if (s[i + 1] <= '6')
              next = (next + prev) % MAX;
          }
          // if two unknown combinations, add current * 15
          // 11-19, 21-26 includes 15 numbers
          else
            next = (next + prev * 15) % MAX;
        }
      } else {
        // if single digit number
        if (s[i] != '0')
          curr = (curr + prev) % MAX;

        // if two digit number
        if (i < s.length() - 1 &&
            (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
          // if next digit is not asterisk, treat normally
          if (s[i + 1] != '*')
            next = (next + prev) % MAX;
          // if next digit is asterisk, multiply by appropriate number
          else
            next = (next + prev * (s[i] == '1' ? 9 : 6)) % MAX;
        }
      }

      prev = curr;
      curr = next;
      next = 0;
    }

    return prev;
  }
};
