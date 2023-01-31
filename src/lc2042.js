/**
 * @param {string} s
 * @return {boolean}
 */
var areNumbersAscending = function(s) {
  let ints = s.split(" ").map(x = > parseInt(x)).filter(x = > !isNaN(x));
  for (let i = 1; i < ints.length; ++i) {
    if (ints[i] <= ints[i - 1]) {
      return false;
    }
  }
  return true;
};
