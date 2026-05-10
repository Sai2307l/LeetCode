class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        idx = {}
        n = len(nums)

        for i in range(n):
            if target-nums[i] in idx:
                return [i,idx[target-nums[i]]]
            idx[nums[i]] = i
        return []
        