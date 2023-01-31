#define VOW(n) (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u')

class Solution {
public:
  int countVowelSubstrings(string word) {

    unordered_map<char, int> vm{};
    vm['a'] = 0;
    vm['e'] = 0;
    vm['i'] = 0;
    vm['o'] = 0;
    vm['u'] = 0;

    int count = 0;

    // find a vowel substring
    int l = 0, r = 0, vowStart = 0, vowEnd = 0;

    // set vowEnd
    // while (VOW(word[vowEnd])) ++vowEnd;

    while (r < word.length()) {
      // r is not pointing at a vowel
      if (!VOW(word[r])) {
        while (r < word.length() && !VOW(word[r]))
          ++r;
        vowStart = vowEnd = l = r;
        // while (VOW(word[vowEnd])) ++vowEnd;
        vm['a'] = 0;
        vm['e'] = 0;
        vm['i'] = 0;
        vm['o'] = 0;
        vm['u'] = 0;

        if (r == word.length()) {
          break;
        }
      }

      // r is pointing at a vowel
      ++vm[word[r]];
      while (vm[word[l]] > 1 && l < r) {
        --vm[word[l++]];
      }

      // cout << l << " " << r << endl;

      if (vm['a'] && vm['e'] && vm['i'] && vm['o'] && vm['u']) {
        count += (l - vowStart + 1);
        // cout << word.substr(l,r-l+1) << " " << (l - vowStart + 1) << endl;
      }

      ++r;
    }

    return count;
  }
};
