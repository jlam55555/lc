/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    
    // negative numbers are not palindromes
    if(x < 0) return false;
    
    // Math.log() won't work on 0
    if(x == 0) return true;
    
    let len = Math.floor(Math.log(x) / Math.log(10));
    for(let i = 0; i < len / 2; i++)
        if((Math.floor(x / Math.pow(10, i)) % 10) != (Math.floor(x / Math.pow(10, len - i)) % 10))
            return false;
    return true;
};
