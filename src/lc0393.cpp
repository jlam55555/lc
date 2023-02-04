class Solution {
public:
  bool validUtf8(vector<int> &data) {
    int i{};
    while (i < data.size()) {
      unsigned char b = data[i] & 0xff;
      // One byte character.
      if (~b & 0x80) {
        // Nothing to do here.
        ++i;
        continue;
      }
      // Multi-byte character.
      int bytes{};
      if ((b & 0xE0) == 0xC0) {
        bytes = 2;
      } else if ((b & 0xF0) == 0xE0) {
        bytes = 3;
      } else if ((b & 0xF8) == 0xF0) {
        bytes = 4;
      } else {
        // Invalid prefix
        return false;
      }
      // String ends before `bytes` bytes.
      if (i + bytes - 1 >= data.size()) {
        return false;
      }
      // Check that each byte in the remaining
      // bytes has the right prefix.
      for (int j{}; j < bytes - 1; ++j) {
        if ((data[i + j + 1] & 0xC0) != 0x80) {
          return false;
        }
      }
      i += bytes;
    }
    return i == data.size();
  }
};
