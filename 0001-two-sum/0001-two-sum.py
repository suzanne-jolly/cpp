class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        nummap={}
        n=len(nums)
        pre=[]
        sum=0
        for i in range(n):
            nummap[nums[i]]=i
        for i in range(n):
            compl=target-nums[i]
            if compl in nummap and nummap[compl]!=i:
                return [i,nummap[compl]]
        return [] # no solution found for the q
        