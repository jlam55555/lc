class Solution {
public:
  // xor is an involution (function that is the inverse of itself),
  // so we simply need to xor the elements together again.
  vector<int> decode(vector<int> &encoded, int first) {
    int next{first};
    for (int i{}; i < encoded.size(); ++i) {
      std::tie(next, encoded[i]) = std::make_pair(encoded[i] ^ next, next);
    }
    encoded.push_back(next);
    return encoded;
  }
};
