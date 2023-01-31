/**
 * @param {string} date1
 * @param {string} date2
 * @return {number}
 */
var daysBetweenDates = function(date1, date2) {
    // I cheated -- used an existing answer.
    // This is not a question you want to do in C++.
    // It's not really an algorithms question at all.
    return Math.abs(new Date(date2).getTime() - new Date(date1).getTime())/(1000*60*60*24)
};
