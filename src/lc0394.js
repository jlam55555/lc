/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
    
    const regex = /(\d+)\[([a-z]+)\]/;
    while (res = regex.exec(s)) {
        const {0: match, 1: repeats, 2: group, index: start} = res;
        s = s.slice(0, start) + group.repeat(repeats) + s.slice(start + match.length);
    }
    return s;
    
};
