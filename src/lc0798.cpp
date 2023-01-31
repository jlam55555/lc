class Solution {
public:
  int bestRotation(vector<int> &A) {
    // calculate score (easy, linear time)
    // trying to get most integers s.t. A[i] <= i
    // shifting right once increases the score by (number of elements with
    // deficit one), but potentially deceases the score by 1

    int score = 0, len = A.size();
    int *deficits = new int[len];
    ::fill(deficits, deficits + len, 0);

    int maxScore, maxScoreIndex = 0;

    for (int i = 0; i < A.size(); ++i) {
      if (A[i] > i)
        deficits[A[i] - i]++;
      else
        score++;
    }

    maxScore = score;
    int originalScore = score;
    for (int i = 0; i < len - 1; ++i) {
      // move "last element" to correct place in deficits

      // moved element is A[len-1-i]
      // old deficit for moved element = A[len-1-i]-(len-1-i)-i
      int currentDeficit = A[len - 1 - i] - (len - 1 - i) - i;
      if (currentDeficit <= 0)
        score--;
      else
        deficits[currentDeficit]--;

      // new deficit for moved element is A[len-1-i]
      if (i + A[len - 1 - i] + 1 < len)
        deficits[i + A[len - 1 - i] + 1]++;

      // calculate new score
      score += deficits[i + 1];

      if (score >= maxScore) {
        maxScore = score;
        maxScoreIndex = len - 1 - i;
      }
    }

    return maxScore == originalScore ? 0 : maxScoreIndex;
  }
};
