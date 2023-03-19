// This sounds like Chinese superstition.....?
//
// General idea:
// - Distribute $1 to each child initially.
// - Distribute an additional $7 to each child we can. Then we are
//   left with some leftover amount 0 <= n < 7.
//   - If there are more than $8 per child, then we can only
//     distribute $8 to children-1.
//   - If there is one child left, and n=3, then we can only
//     distribute $8 to children-2.
//   - Otherwise, we distribute $8 to as (money-children)/7
//     children.
//
// Like many people, I failed this easy question a number
// of times before arriving at the correct solution. However,
// I don't think it's a terrible question; it shows that there's
// actually a logical brain teaser.
class Solution {
public:
  int distMoney(int money, int children) {
    if ((money -= children) < 0) {
      return -1;
    }

    if (money > children * 7) {
      return children - 1;
    }

    if (money / 7 == children - 1 && money % 7 == 3) {
      return children - 2;
    }

    return money / 7;
  }
};
