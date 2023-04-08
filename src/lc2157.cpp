// Initial thoughts: Union-find to group together words?
//
// The restriction that each word cannot have duplicate letters
// makes me want to use a bitmask (32-bit int) to store each
// word. Checking if two words are connected should be a fairly
// straightforward operation:
// - Check if the hamming_dist(word1, word2) < 2
//   (words can be equivalent without more than one addition/
//   deletion, or words are already equal).
// - Check if hamming_dist(word1, word2) == 2 and one is
//   an addition and one is a deletion.
//
// We can use this as the basis of a O(N^2) algorithm, with
// union-find to avoid joining words in the same group already.
// However, this TLE's, so we need to further optimize.
//
// We improve the search to a O(27*N) time and O(27*N) space
// algorithm by storing each word, with at most one letter
// removed. We can check if a word is connected to another
// by seeing if, after removing at most one letter, it is an
// element of this set. We never try adding a letter to the word;
// this is analogous to doing a bidirectional BFS to limit the
// search frontier.
//
// After looking at some of the other solutions, it seems that
// another viable solution, with a fairly similar runtime,
// is using a standard graph search (DFS/BFS). This uses
// significantly less space than the Union-Find (probably roughly
// 27x smaller), and has similar runtime. @votrubac provides
// a sample of both solutions.
//
// I found this a pretty fun problem.
class UnionFind {
  struct Element {
    int grp;
    int grp_sz;
  };
  int group_count_;
  int max_group_size_;
  std::vector<Element> grps_;

public:
  UnionFind(int n) : group_count_{n}, max_group_size_{1} {
    grps_.reserve(n);
    for (int i{}; i < n; ++i) {
      grps_.push_back({i, 1});
    }
  }
  int Find(int g) {
    while (g != grps_[g].grp) {
      g = grps_[g].grp = grps_[grps_[g].grp].grp;
    }
    return g;
  }
  void Union(int g1, int g2) {
    if ((g1 = Find(g1)) == (g2 = Find(g2))) {
      return;
    }
    auto g1_sz{grps_[g1].grp_sz}, g2_sz{grps_[g2].grp_sz};
    if (g1_sz < g2_sz) {
      grps_[g1].grp = g2;
      grps_[g2].grp_sz = g1_sz + g2_sz;
    } else {
      grps_[g2].grp = g1;
      grps_[g1].grp_sz = g1_sz + g2_sz;
    }
    max_group_size_ = std::max(max_group_size_, g1_sz + g2_sz);
    --group_count_;
  }
  int GroupCount() const { return group_count_; }
  int MaxGroupSize() const { return max_group_size_; }
};

class Solution {
public:
  vector<int> groupStrings(vector<string> &words) {
    UnionFind uf(words.size());
    std::unordered_map<unsigned, int> seen;
    for (int i{}, n(words.size()); i < n; ++i) {
      // Convert word to int.
      unsigned word{};
      for (auto c : words[i]) {
        word |= 1u << (c - 'a');
      }

      // Check word by itself.
      auto &self{seen[word]};
      if (self) {
        uf.Union(i, self - 1);
      } else {
        self = i + 1;
      }

      // Try removing one character from the word.
      for (char c : words[i]) {
        auto &neighbor{seen[word & ~(1u << (c - 'a'))]};
        if (neighbor) {
          uf.Union(i, neighbor - 1);
        } else {
          neighbor = i + 1;
        }
      }
    }
    return {uf.GroupCount(), uf.MaxGroupSize()};
  }
};
