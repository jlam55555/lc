/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {

  if (!strs.length)
    return '';

  let prefix = strs.splice(0, 1)[0], str, i;

  for (str of strs) {

    if (prefix.length > str.length) {
      prefix = prefix.slice(0, str.length);
    }
    for (i = 0; i < str.length; i++) {
      if (prefix.charAt(i) != str.charAt(i)) {
        prefix = prefix.slice(0, i);
        break;
      }
    }
  }

  return prefix;
};
