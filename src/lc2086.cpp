class Solution {
public:
  int minimumBuckets(string street) {
    int count = 0;

    // edge case: only an H
    if (street == "H") {
      return -1;
    }

    for (int i = 0; i < street.length(); ++i) {
      // house in need of a bucket
      if (street[i] == 'H' &&
          ((!i || street[i - 1] != 'b') &&
           (i == street.length() - 1 || street[i + 1] != 'b'))) {

        // attempt to put one to right
        if (i < street.length() - 1 && street[i + 1] == '.') {
          street[i + 1] = 'b';
          ++count;
        }
        // attempt to put one to left
        else if (i && street[i - 1] == '.') {
          ++count;
        }
        // nowhere to put it
        else {
          return -1;
        }
      }
    }

    return count;
  }
};
