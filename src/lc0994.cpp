class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {

    // get height, width
    int height = grid.size(), width = height ? grid[0].size() : 0, i, j,
        steps = 0;
    bool oranges_infected_this_step;
    list<pair<int, int>> normal_oranges{};
    list<pair<int, int>>::iterator orange, end;

    // make lists of normal oranges
    // change markings to: no orange or fresh orange = 101, rotten orange = 0
    // want to mark rotten oranges with the round that they get rotten in for
    // the below algorithm to work easily
    for (i = 0; i < height; ++i) {
      for (j = 0; j < width; ++j) {
        if (grid[i][j] == 1) {
          normal_oranges.push_back(pair{i, j});
        }

        grid[i][j] = grid[i][j] < 2 ? 101 : 0;
      }
    }

    // edge case: no normal oranges
    if (!normal_oranges.size())
      return 0;

    do {
      oranges_infected_this_step = false;
      ++steps;

      for (orange = normal_oranges.begin(), end = normal_oranges.end();
           orange != end;) {
        i = (*orange).first;
        j = (*orange).second;

        // if any adjacent are rotten from the previous round, then this one
        // becomes rotten; mark it with the current round number
        // either (< steps) or (== steps-1) should work
        if ((j && grid[i][j - 1] < steps) || (i && grid[i - 1][j] < steps) ||
            (i < height - 1 && grid[i + 1][j] < steps) ||
            (j < width - 1 && grid[i][j + 1] < steps)) {
          grid[i][j] = steps;
          oranges_infected_this_step = true;
          normal_oranges.erase(orange++);
        } else {
          orange++;
        }
      }

    } while (oranges_infected_this_step && normal_oranges.size());

    return oranges_infected_this_step ? steps : -1;
  }
};
