#
# @lc app=leetcode.cn id=416 lang=python3
# @lcpr version=30204
#
# [416] 分割等和子集
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
def zeroonepack_exact_bool(nums, target):
    n = len(nums)
    dp = [True] + [False] * target
    for v in nums:
        for i in range(target, v - 1, -1):
            dp[i] |= dp[i - v]
    return dp[target]

class Solution:


    def canPartition(self, nums: List[int]) -> bool:
        # 恰好
        total = sum(nums)
        if total % 2 != 0:
            return False
        half = total // 2
        return zeroonepack_exact_bool(nums, half)

# @lc code=end



#
# @lcpr case=start
# [1,5,11,5]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,5]\n
# @lcpr case=end

#

