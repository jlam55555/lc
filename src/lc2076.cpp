typedef vector<int> vi;
typedef vector<vi> vvi;

class union_find {
public:
  int group_count;
  ::vector<int> arr, group_sizes;
  vector<unordered_set<int>> memsets;

public:
  union_find(int size);
  int find(int e);
  bool unio(int e1, int e2);

  int size(void);
  int groups(void);
};

union_find::union_find(int size)
    : arr{::vector<int>(size)}, group_sizes{::vector<int>(size, 1)},
      group_count{size}, memsets{vector<unordered_set<int>>(size)} {
  int i;

  // initialize all elements to singleton set
  for (i = 0; i < size; ++i) {
    arr[i] = i;
  }
}

int union_find::find(int e) {
  int root = e, tmp;

  if (e < 0 || e >= size()) {
    throw ::invalid_argument{"element out of bounds"};
  }

  while (arr[root] != root) {
    root = arr[root];
  }

  // path compression
  while (arr[e] != root) {
    tmp = arr[e];
    arr[e] = root;
    e = tmp;
  }

  return root;
}

bool union_find::unio(int e1, int e2) {
  int g1 = find(e1), g2 = find(e2), new_size;

  if (g1 == g2) {
    // no union
    return false;
  }

  new_size = group_sizes[g1] + group_sizes[g2];
  --group_count;

  if (group_sizes[g1] < group_sizes[g2]) {
    arr[g1] = g2;
    group_sizes[g2] = new_size;
    memsets[g2].insert(memsets[g1].begin(), memsets[g1].end());
  } else {
    arr[g2] = g1;
    group_sizes[g1] = new_size;
    memsets[g1].insert(memsets[g2].begin(), memsets[g2].end());
  }

  return true;
}

int union_find::size(void) { return arr.size(); }

int union_find::groups(void) { return group_count; }

class Solution {
public:
  vector<bool> friendRequests(int n, vvi &restrictions, vvi &requests) {
    vector<bool> res{};

    // uf is the list of islands
    union_find uf{n};

    // gather the list of restrictions into a more usable form
    vvi r(n);
    for (const auto &restriction : restrictions) {
      r[restriction[0]].push_back(restriction[1]);
      r[restriction[1]].push_back(restriction[0]);

      uf.memsets[restriction[0]].insert(restriction[1]);
      uf.memsets[restriction[1]].insert(restriction[0]);
    }

    // process requests
    for (const auto &request : requests) {
      int f1 = request[0], f2 = request[1];
      int g1 = uf.find(f1), g2 = uf.find(f2);

      for (auto i : uf.memsets[g1]) {
        if (uf.find(i) == g2) {
          goto fail;
        }
      }
      for (auto i : uf.memsets[g2]) {
        if (uf.find(i) == g1) {
          goto fail;
        }
      }

      res.push_back(true);
      uf.unio(g1, g2);
      continue;

    fail:
      res.push_back(false);
    }

    return res;
  }
};
