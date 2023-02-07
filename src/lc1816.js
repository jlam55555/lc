/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function(s, k) {
    // I'm lazy so using Javascript.
    return s.split(" ").slice(0, k).join(" ");
};
