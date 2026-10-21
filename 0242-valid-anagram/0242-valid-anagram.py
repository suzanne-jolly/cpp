class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):
            return False
        nums={}
        numt={}
        for ch in s:
            nums[ch]=nums.get(ch,0)+1
        for ch in t:
            numt[ch]=numt.get(ch,0)+1
        if nums==numt:
            return True
        else:
            return False
        return False

        