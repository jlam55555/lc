/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let lastDigit = digits.length - 1;
    do {
        digits[lastDigit] = (digits[lastDigit] + 1) % 10;
    } while (!digits[lastDigit--] && lastDigit >= 0);
    if(lastDigit == -1 && !digits[0])
        digits.unshift(1);
    return digits;
};
