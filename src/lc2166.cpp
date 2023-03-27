// Could use `std::bitset<>` for this, but that'd be cheating
// a little bit. This also allows for dynamically-sized bitsets.
//
// This solution has good memory usage but terrible runtime.
// The main reason is that the `flip() ` and `toString()` functions
// are O(n).
//
// Most of the answers suggest to store two strings: a regular
// and a flipped version, and keep track of the flips. By doing
// this, you are caching both the flipped version and the string.
//
// I think we could also optimize this by keeping track of the number
// of flips, but without keeping a flipped copy. This would
// require some XOR magic that my brain is currently too tired
// to handle.
class Bitset {
  int size_, bytes_, count_{};
  unsigned char *bs_, last_byte_mask_;

public:
  Bitset(int size)
      : size_{size}, bytes_{(size + 7) >> 3}, bs_{static_cast<unsigned char *>(
                                                  std::calloc(bytes_, 1))} {
    // last_byte_mask_ used in flip().
    int rem_bytes{size_ & 0x7};
    if (rem_bytes == 0) {
      rem_bytes = 8;
    }
    last_byte_mask_ = static_cast<unsigned char>((1u << rem_bytes) - 1);
  }

  ~Bitset() { std::free(bs_); }

  void fix(int idx) {
    count_ += !(bs_[idx >> 3] & (1u << (idx & 0x7)));
    bs_[idx >> 3] |= 1u << (idx & 0x7);
  }

  void unfix(int idx) {
    count_ -= !!(bs_[idx >> 3] & (1u << (idx & 0x7)));
    bs_[idx >> 3] &= ~(1u << (idx & 0x7));
  }

  void flip() {
    for (int i{}; i < bytes_; ++i) {
      bs_[i] ^= 0xff;
    }
    bs_[bytes_ - 1] &= last_byte_mask_;
    count_ = size_ - count_;
  }

  bool all() { return count_ == size_; }

  bool one() { return !!count_; }

  int count() { return count_; }

  string toString() {
    std::string res(bytes_ * 8, 0);
    for (int i{}; i < bytes_; ++i) {
      res[(i << 3) + 0] = !!(bs_[i] & 0x01) + '0';
      res[(i << 3) + 1] = !!(bs_[i] & 0x02) + '0';
      res[(i << 3) + 2] = !!(bs_[i] & 0x04) + '0';
      res[(i << 3) + 3] = !!(bs_[i] & 0x08) + '0';
      res[(i << 3) + 4] = !!(bs_[i] & 0x10) + '0';
      res[(i << 3) + 5] = !!(bs_[i] & 0x20) + '0';
      res[(i << 3) + 6] = !!(bs_[i] & 0x40) + '0';
      res[(i << 3) + 7] = !!(bs_[i] & 0x80) + '0';
    }
    res.resize(size_);
    return res;
  }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
