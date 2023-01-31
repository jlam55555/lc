class Solution {
public:
  string reorderSpaces(string text) {

    int num_spaces = 0, num_words = 0;

    // count the number of spaces
    // count the number of words
    for (int i = 0; i < text.length(); ++i) {
      if (text[i] == ' ')
        ++num_spaces;
      if (text[i] != ' ' && (!i || text[i - 1] == ' '))
        ++num_words;
    }

    string res(text.length(), ' ');
    int spaces_length = num_words > 1 ? num_spaces / (num_words - 1) : 0;
    int i, j, k;
    for (i = j = k = 0; i < num_words; ++i) {
      // find start of next word
      while (text[j] == ' ')
        ++j;

      // copy word over
      while (text[j] != ' ' && j < text.length())
        res[k++] = text[j++];

      // copy over spaces
      for (int l = 0; l < spaces_length; ++l)
        ++k;
    }

    return res;
  }
};
