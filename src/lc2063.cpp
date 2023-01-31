#define VOW(n) (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u')

class Solution {
public:
  long long countVowels(string word) {
    // counting problem
    int n = word.length();
    long long count = 0;
    long long multiplier = 0;

    int i;
    for (i = 0; i < n / 2; ++i) {
      multiplier += n - 2 * i;
      if (VOW(word[i]))
        count += multiplier;
      if (VOW(word[n - 1 - i]))
        count += multiplier;
    }

    // count the middle element for odd length strings
    if (n % 2 == 1) {
      multiplier += n - 2 * i;
      if (VOW(word[i]))
        count += multiplier;
    }

    return count;
  }
};
