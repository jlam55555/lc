int trailingZeroes(int n) {

  int i, res, log5;

  // number of 10s is min(factors of 2, factors of 5) for all 5<=i<=n
  for (i = 1, res = 0, log5 = log(n) / log(5); i <= log5; i++)
    res += n / pow(5, i);
  return res;
}

/*
5!: 5, 2;
10!: 5, 5, 2, 2;
15!: 5, 5, 5, 2, 2, 2;
20!: 5, 5, 5, 5, 2, 2, 2, 2;
25!: 5, 5, 5, 5, 5, 2, 2, 2, 2, 2;

all dependent on number of 5s (# 2s is always greater)
5: 1;
10: 2;
15: 3;
20: 4;
25: 5 + 1;
30: 7;
...
50: + 1
...
75: + 1
...
125: + 2;

number of 0s is:
- number of 5s
- +1 for every multiple of every power of 5 >= 25 and less than n
*/
