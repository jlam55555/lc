class Solution {
public:
  int minTimeToType(string word) {
    int time = word.length();

    char prev = 'a';
    for (int i = 0; i < word.size(); ++i) {
      time += min(abs(word[i] - prev),
                  min(abs(word[i] + 26 - prev), abs(word[i] - 26 - prev)));
      prev = word[i];
    }

    return time;
  }
};
