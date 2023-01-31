/**
 * @param {number[][]} accounts
 * @return {number}
 */
var maximumWealth = function(accounts) {
    return accounts.reduce((acc, acct) => Math.max(acc, acct.reduce((a, s) => a + s)), 0)
};
