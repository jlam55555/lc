class Solution {
public:
  string originalDigits(string s) {
    int charFreq[26] = {0};

    for (char c : s) {
      charFreq[c - 'a']++;
    }

    int digitFreq[10] = {0};

    // get zeros
    digitFreq[0] = charFreq['z' - 'a'];
    charFreq['e' - 'a'] -= digitFreq[0];
    charFreq['r' - 'a'] -= digitFreq[0];
    charFreq['o' - 'a'] -= digitFreq[0];

    // get twos
    digitFreq[2] = charFreq['w' - 'a'];
    charFreq['t' - 'a'] -= digitFreq[2];
    charFreq['o' - 'a'] -= digitFreq[2];

    // get fours
    digitFreq[4] = charFreq['u' - 'a'];
    charFreq['f' - 'a'] -= digitFreq[4];
    charFreq['o' - 'a'] -= digitFreq[4];
    charFreq['r' - 'a'] -= digitFreq[4];

    // get sixes
    digitFreq[6] = charFreq['x' - 'a'];
    charFreq['s' - 'a'] -= digitFreq[6];
    charFreq['i' - 'a'] -= digitFreq[6];

    // get eights
    digitFreq[8] = charFreq['g' - 'a'];
    charFreq['e' - 'a'] -= digitFreq[8];
    charFreq['i' - 'a'] -= digitFreq[8];
    charFreq['h' - 'a'] -= digitFreq[8];
    charFreq['t' - 'a'] -= digitFreq[8];

    // get ones
    digitFreq[1] = charFreq['o' - 'a'];

    // get threes
    digitFreq[3] = charFreq['t' - 'a'];

    // get fives
    digitFreq[5] = charFreq['f' - 'a'];
    charFreq['i' - 'a'] -= digitFreq[5];

    // get sevens
    digitFreq[7] = charFreq['s' - 'a'];

    // get nines
    digitFreq[9] = charFreq['i' - 'a'];

    string res;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < digitFreq[i]; ++j) {
        res += i + '0';
      }
    }

    return res;
  }
};
