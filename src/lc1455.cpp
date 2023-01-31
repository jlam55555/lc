/**
 * @param {string} sentence
 * @param {string} searchWord
 * @return {number}
 */
var isPrefixOfWord = (sentence, searchWord) = > {
  const words = sentence.split(' ');
  for (let i = 0; i < words.length; ++i)
    if (words[i].slice(0, searchWord.length) == searchWord)
      return i + 1;
  return -1;
}
