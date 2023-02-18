/**
 * @param {string} date
 * @return {number}
 */

 // I am lazy, so I'm using JS's date library.
 // Reference: https://stackoverflow.com/a/8619946
var dayOfYear = function(date) {
    const d2 = new Date(date);
    const d1 = new Date(d2.getFullYear(), 0, 0);

    return (d2 - d1) / 1000 / 60 / 60 / 24;
};
