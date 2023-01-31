/**
 * @param {string} command
 * @return {string}
 */
var interpret = function(c) {
    c = c.replace(/\(al\)/g, 'al');
    c = c.replace(/\(\)/g, 'o');
    
    return c;
};
