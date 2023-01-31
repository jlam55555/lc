namespace {

constexpr char r1[]{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
    r2[]{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
    r3[]{'z', 'x', 'c', 'v', 'b', 'n', 'm'};

template <ssize_t N>
constexpr std::array<bool, 26> CharToMap(const char (&chars)[N]) noexcept {
  std::array<bool, 26> res{false};
  for (auto i{0}; i < N; ++i) {
    res[chars[i] - 'a'] = true;
  }
  return res;
}

constexpr auto r1m{CharToMap(r1)}, r2m{CharToMap(r2)}, r3m{CharToMap(r3)};

template <ssize_t N1, ssize_t N2, ssize_t N3>
constexpr std::array<int, 26> LetterMap(const char (&r1)[N1],
                                        const char (&r2)[N2],
                                        const char (&r3)[N3]) noexcept {
  std::array<int, 26> res{};
  for (auto i{0}; i < N1; ++i) {
    res[r1[i] - 'a'] = 0;
  }
  for (auto i{0}; i < N2; ++i) {
    res[r2[i] - 'a'] = 1;
  }
  for (auto i{0}; i < N3; ++i) {
    res[r3[i] - 'a'] = 2;
  }
  return res;
}

constexpr auto letter_map = LetterMap(r1, r2, r3);

constexpr std::array<bool, 26> rows[]{r1m, r2m, r3m};

bool FitsInRow(const std::string_view s, std::array<bool, 26> rm) {
  for (auto c : s) {
    if (!rm[(c | 0x20) - 'a']) {
      return false;
    }
  }
  return true;
}

}; // namespace

class Solution {
public:
  std::vector<std::string>
  findWords(std::vector<std::string> &words) const noexcept {
    std::vector<std::string> res{};
    for (auto &word : words) {
      if (FitsInRow(word, rows[letter_map[(word[0] | 0x20) - 'a']])) {
        res.push_back(std::move(word));
      }
    }
    return res;
  }
};
