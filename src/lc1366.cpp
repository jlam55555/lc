class Solution {
public:
  string rankTeams(vector<string> &votes) {
    vector<vector<int>> count(26, vector<int>(27));
    for (char &c : votes[0])
      count[c - 'A'][26] = c;

    for (string &vote : votes)
      for (int i = 0; i < vote.length(); ++i)
        --count[vote[i] - 'A'][i];
    sort(count.begin(), count.end());
    string res;
    for (int i = 0; i < votes[0].length(); ++i)
      res += count[i][26];
    return res;
  }

  //     struct rank {
  //         int ranks[26] = {0};
  //         int count = 0;
  //         char letter;

  //         bool cmp(const rank& r1, const rank& r2, int lvl) {
  //             if (lvl == 26) {
  //                 return r1.letter < r2.letter;
  //             }

  //             if (r1.ranks[lvl] == r2.ranks[lvl]) {
  //                 return cmp(r1, r2, lvl+1);
  //             } else {
  //                 return r1.ranks[lvl] > r2.ranks[lvl];
  //             }
  //         }

  //         inline bool operator()(const rank& r1, const rank& r2) {
  //             return cmp(r1, r2, 0);
  //         }
  //     };

  //     string rankTeams(vector<string>& votes) {

  //         rank rankedVotes[26] = {0};
  //         for (int i = 0; i < 26; ++i) {
  //             rankedVotes[i].letter = i + 'A';
  //         }

  //         for (auto vote : votes) {
  //             for (int i = 0; i < vote.length(); ++i) {
  //                 ++rankedVotes[vote[i]-'A'].ranks[i];
  //                 ++rankedVotes[vote[i]-'A'].count;
  //             }
  //         }

  //         sort(rankedVotes, rankedVotes+26, rank());

  //         string res = "";
  //         for (int i = 0; i < 26; ++i) {
  //             if (!rankedVotes[i].count) {
  //                 continue;
  //             }

  //             res += rankedVotes[i].letter;
  //         }

  //         return res;
  //     }
};
