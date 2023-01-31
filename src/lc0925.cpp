class Solution {
public:
  bool isLongPressedName(string name, string typed) {
    int lastLetter, lastLetterLen, typedLen, i, j;

    for (i = j = 0; i < name.length();) {
      // get run length in original
      lastLetter = name[i];
      lastLetterLen = 0;
      while (i < name.length() && name[i] == lastLetter) {
        ++i;
        ++lastLetterLen;
      }

      // get run length in latter
      typedLen = 0;
      while (j < typed.length() && typed[j] == lastLetter) {
        ++j;
        ++typedLen;
      }

      if (typedLen < lastLetterLen)
        return false;
    }

    return j == typed.length();
  }
};
