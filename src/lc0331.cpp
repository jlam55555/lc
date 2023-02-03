// Algorithm: Parse each subtree linearly. I.e., we can imagine
// each subtree to either be trivial ("#") or to be of the form
// "n,(serialized subtree 1),(serialized subtree 2)". At the end
// of the algorithm, we expect the whole string to be consumed
// and all subtrees to be verified.
class Solution {
public:
  // Checks if there is a valid subtree beginning at index `i`.
  // Returns the ending index if valid, otherwise `std::nullopt`.
  std::optional<int> Check(const std::vector<bool> &serialized, int i) {
    // Reached the end of the string; not valid.
    if (i >= serialized.size()) {
      return {};
    }

    // Base case: empty subtree. (I.e., we've reached a '#'.)
    if (!serialized[i]) {
      return i + 1;
    }

    // Check left subtree.
    auto res_left = Check(serialized, i + 1);
    if (!res_left) {
      return {};
    }
    // Check right subtree, beginning at the end index of
    // the left subtree.
    return Check(serialized, *res_left);
  }

  bool isValidSerialization(string preorder) {
    // Parse the preorder string as a vector.
    // Just makes the rest of the logic a little more palatable.
    // False if null subtree, true otherwise.
    std::vector<bool> serialized;
    char prev{-1};
    for (auto c : preorder) {
      if (c == ',')
        ;
      else if (c == '#') {
        serialized.push_back(false);
      } else if (std::isdigit(c) && !std::isdigit(prev)) {
        serialized.push_back(true);
      }
      prev = c;
    }

    // Recursively parse.
    auto index_opt = Check(serialized, 0);
    return index_opt && *index_opt == serialized.size();
  }
};
