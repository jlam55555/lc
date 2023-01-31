class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        sChars, tChars = dict(), dict()
        
        if len(s) != len(t):
            return False
        
        l = len(s)
        for i in range(l):
            if s[i] in sChars:
                if (t[i] not in tChars) or (sChars[s[i]] != tChars[t[i]]):
                    return False
            elif t[i] in tChars:
                return False
            else:
                sChars[s[i]] = i
                tChars[t[i]] = i
                
        return True
