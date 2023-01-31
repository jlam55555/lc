/**
 * @param {string} text
 * @param {string} first
 * @param {string} second
 * @return {string[]}
 */
var findOcurrences = (text, first, second) =>
    text.split(' ').filter((word, i, arr) => i >= 2 && arr[i-1] == second && arr[i-2] == first);
