#
# @lc app=leetcode.cn id=494 lang=python3
# @lcpr version=30204
#
# [494] 目标和
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
def zeroonepack_exact_cnt(nums, target, c = None):
    n = len(nums)
    dp = [1] + [0] * target
    for v in nums:
        for i in range(target, v - 1, -1):
            dp[i] += dp[i - v]
    return dp[target]

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # s   x  - (s - x) = t => 2x =  s + t
        # s - s = s - (s + t) / 2 = (s - t) / 2
        total = sum(nums) - target
        if total % 2 != 0 or total < 0:
            return 0
        return zeroonepack_exact_cnt(nums,total // 2)
        
# @lc code=end



#
# @lcpr case=start
# [1,1,1,1,1]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n1\n
# @lcpr case=end

#

