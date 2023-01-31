class union_find {
public:
  int group_count;
  ::vector<int> arr, group_sizes;

public:
  union_find(int size);
  int find(int e);
  bool unio(int e1, int e2);

  int size(void);
  int groups(void);
};

// haskell-style indenting? not sure if this is blasphemy
union_find::union_find(int size)
    : arr{::vector<int>(size)}, group_sizes{::vector<int>(size, 1)},
      group_count{size} {
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
  } else {
    arr[g2] = g1;
    group_sizes[g1] = new_size;
  }

  return true;
}

int union_find::size(void) { return arr.size(); }

int union_find::groups(void) { return group_count; }

class Solution {
public:
  void dfs(vector<vector<int>> &grid, vector<int> &islandSizes, int i, int j,
           int dim1, int dim2) {
    if (i < 0 || i >= dim1 || j < 0 || j >= dim2 || !grid[i][j] ||
        grid[i][j] == currIsland) {
      return;
    }

    grid[i][j] = currIsland;
    ++islandSizes[currIsland];

    dfs(grid, islandSizes, i - 1, j, dim1, dim2);
    dfs(grid, islandSizes, i + 1, j, dim1, dim2);
    dfs(grid, islandSizes, i, j - 1, dim1, dim2);
    dfs(grid, islandSizes, i, j + 1, dim1, dim2);
  }

  int currIsland;

  int largestIsland(vector<vector<int>> &grid) {
    int dim1 = grid.size(), dim2 = grid[0].size();
    int size = dim1 * dim2;

    vector<int> islandSizes(size + 2, 0);

    currIsland = 2;

    for (int i = 0; i < dim1; ++i) {
      for (int j = 0; j < dim2; ++j) {
        // if new island
        if (grid[i][j] == 1) {
          dfs(grid, islandSizes, i, j, dim1, dim2);
          ++currIsland;
        }
      }
    }

    // if single island
    if (currIsland == 3 && islandSizes[2] == size) {
      return size;
    }

    int maxSize = 1;
    for (int i = 0; i < dim1; ++i) {
      for (int j = 0; j < dim2; ++j) {
        unordered_set<int> islands;

        // get islands around this point
        if (i >= 1 && grid[i - 1][j])
          islands.insert(grid[i - 1][j]);
        if (i < dim1 - 1 && grid[i + 1][j])
          islands.insert(grid[i + 1][j]);
        if (j >= 1 && grid[i][j - 1])
          islands.insert(grid[i][j - 1]);
        if (j < dim2 - 1 && grid[i][j + 1])
          islands.insert(grid[i][j + 1]);

        int count = 1;
        for (auto island : islands) {
          count += islandSizes[island];
        }
        maxSize = max(maxSize, count);
      }
    }

    return maxSize;
  }

  //     int largestIsland(vector<vector<int>>& grid) {
  //         int dim1 = grid.size(), dim2 = grid[0].size();
  //         int size = dim1 * dim2;
  //         vector<int> mtuf(size, -1);
  //         union_find uf{size};

  //         for (int i = 0; i < dim1; ++i) {
  //             for (int j = 0; j < dim2; ++j) {
  //                 if (!grid[i][j]) {
  //                     continue;
  //                 }
  //                 int n = i * dim2 + j;

  //                 if (i >= 1 && grid[n+1]) uf.unio(n, i*dim2+(j+1));
  //             }
  //         }

  //         // check if no unoccupied
  //         if (uf.groups() == 1) {
  //             return size;
  //         }

  //         int ans = 1;
  //         for (int i = 0; i < dim1; ++i) {
  //             for (int j = 0; j < dim2; ++j) {
  //                 unordered_set<int> groups;

  //                 if (i >= 1 && grid[i-1][j])
  //                 groups.insert(uf.find((i-1)*dim2+j)); if (i < dim1-1 &&
  //                 grid[i+1][j]) groups.insert(uf.find((i+1)*dim2+j)); if (j
  //                 >= 1 && grid[i][j-1]) groups.insert(uf.find(i*dim2+(j-1)));
  //                 if (j < dim2-1 && grid[i][j+1])
  //                 groups.insert(uf.find(i*dim2+(j+1)));

  //                 int island_size = 0;
  //                 for (auto group : groups) {
  //                     island_size += uf.group_sizes[group];
  //                 }
  //                 ans = max(ans, 1+island_size);

  //             }
  //         }

  //         return ans;
  //     }
};
