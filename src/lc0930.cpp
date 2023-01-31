class Solution {
public:
  //     int numSubarraysWithSum(vector<int>& A, int S) {
  //         int len = A.size(), *P = new int[len+1], i, pPos, count;
  //         ::fill(P, P+len+1, 0);

  //         for (i = 0, pPos = 0, count = 0, P[0] = 1; i < len; ++i) {
  //             if (A[i]) {
  //                 if (pPos >= S)
  //                     count += S
  //                         ? P[pPos] * P[pPos-S]
  //                         : (P[pPos]-1) * P[pPos] / 2;
  //                 ++pPos;
  //             }
  //             P[pPos]++;
  //         }
  //         if (pPos >= S)
  //             count += S
  //                 ? P[pPos] * P[pPos-S]
  //                 : (P[pPos]-1) * P[pPos] / 2;
  //         return count;
  //     }

  //     int numSubarraysWithSum(vector<int> &A, int S) {
  //         int len = A.size(), *P = new int[len + 1], *C = new int[len + 1],
  //         i, totalCount;

  //         ::fill(P, P+len+1, 0);
  //         ::fill(C, C+len+1, 0);

  //         C[0] = 1;
  //         for (i = 0; i < len; ++i) {
  //             P[i+1] = A[i] + P[i];
  //             ++C[P[i+1]];
  //         }

  //         if (!S) {
  //             for (i = 0, totalCount = 0; i <= len; ++i)
  //                 totalCount += C[i] * (C[i] - 1) / 2;
  //             return totalCount;
  //         }

  //         // count counts P[i-S]
  //         for (i = 1, totalCount = 0; i <= len; ++i)
  //             if (P[i] >= S)
  //                 totalCount += C[P[i]-S];

  //         return totalCount;
  //     }

  int numSubarraysWithSum(vector<int> &A, int S) {
    int len = A.size(), sumLo, sumHi, iLo, iHi, j, ans;

    for (iLo = iHi = sumLo = sumHi = j = ans = 0; j < len; ++j) {
      sumLo += A[j];
      while (iLo < j && sumLo > S)
        sumLo -= A[iLo++];

      sumHi += A[j];
      while (iHi < j && sumHi - A[iHi] >= S)
        sumHi -= A[iHi++];

      if (sumLo == S)
        ans += iHi - iLo + 1;
    }
    return ans;
  }
};
