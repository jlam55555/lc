/**
 * @param {string} s
 * @return {string}
 */
var sortSentence = function(s) {
    // Lazy, so doing this in JS.
    const output = [];
    s.split(" ")
        .map(word => [word.slice(0, -1), parseInt(word.slice(-1)) - 1])
        .forEach(([w, i]) => output[i] = w);
    
    return output.join(" ");
};
