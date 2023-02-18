/**
 * @param {number} day
 * @param {number} month
 * @param {number} year
 * @return {string}
 */

// Again, I'm lazy and will defer to JS's builtin
// Date library.
const days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];

var dayOfTheWeek = function(day, month, year) {
    // Note that month is zero-indexed. See
    // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/Date
    return days[new Date(year, month-1, day).getDay()];
};
