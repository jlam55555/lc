/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    return /^\s*[\+\-]?((\d*\.?\d+)|(\d+\.?\d*))(e[\+\-]?\d+)?\s*$/.test(s);
};
