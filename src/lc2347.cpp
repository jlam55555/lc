class Solution {
public:
  string bestHand(vector<int> &ranks, vector<char> &suits) {
    std::vector<int> suit_freqs(4), rank_freqs(14);
    for (int i{}, n(ranks.size()); i < n; ++i) {
      ++rank_freqs[ranks[i] - 1];
      ++suit_freqs[suits[i] - 'a'];
    }
    if (*std::max_element(suit_freqs.begin(), suit_freqs.end()) >= 5) {
      return "Flush";
    }
    if (auto max_rank{*std::max_element(rank_freqs.begin(), rank_freqs.end())};
        max_rank >= 2) {
      return max_rank >= 3 ? "Three of a Kind" : "Pair";
    }
    return "High Card";
  }
};
