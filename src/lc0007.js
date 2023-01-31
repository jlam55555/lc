/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    
    let rev = 0, pop;
    
    const INT_MAX = (2 << 29) * 2 - 1;
    const INT_MIN = 2 << 30;
        
    while(x != 0) {
        pop = x % 10;
        x = Math.trunc(x/10);
        
        if (rev > Math.trunc(INT_MAX/10) || (rev == Math.trunc(INT_MAX / 10) && pop > 7)) return 0;
        if (rev < Math.trunc(INT_MIN/10) || (rev == Math.trunc(INT_MIN / 10) && pop < -8)) return 0;
        
        rev = rev * 10 + pop;
    }
    return rev;

};
