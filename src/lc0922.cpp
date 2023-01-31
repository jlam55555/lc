class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &A) {
    int evenHead = 0, oddHead = 1, len = A.size();

    while (1) {
      while (evenHead < len && !(A[evenHead] % 2))
        evenHead += 2;

      while (oddHead < len && A[oddHead] % 2)
        oddHead += 2;

      if (evenHead >= len)
        break;

      ::swap(A[evenHead], A[oddHead]);
    }

    return A;
  }
};
