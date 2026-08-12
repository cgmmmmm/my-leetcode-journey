class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        # solved in under 3 minutes in one try (best record for medium)
        occurence = {}
        l = 0
        maxRes = 0

        for r in range(len(nums)):
            occurence[nums[r]] = occurence.get(nums[r], 0) + 1
            while occurence[nums[r]] > k:
                occurence[nums[l]] -= 1
                l += 1
            maxRes = max(maxRes, r-l+1)

        return maxRes
