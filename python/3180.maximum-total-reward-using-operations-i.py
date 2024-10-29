#
# @lc app=leetcode.cn id=3180 lang=python3
# @lcpr version=30204
#
# [3180] 执行操作可获得的最大总奖励 I
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
    def maxTotalReward1(self, rewardValues: List[int]) -> int:
        @cache
        def dfs(cur):
            ans = cur
            for j in range(0, len(rewardValues)):
                if (rewardValues[j] > cur):
                    ans = max(ans, dfs(cur + rewardValues[j]))
            return ans
        return dfs(0)
    
    def maxTotalReward2(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        total = rewardValues[-1] * 2
        # dp[v] 能否价格到达v
        dp = [False] * total
        dp[0] = True
        for v in rewardValues:
            for i in range(min((total - 1), 2 * v - 1), v - 1, -1):
                # old total - v
                # add v
                if v > i - v:
                    dp[i] |= dp[i - v]
        for i in range(len(dp) - 1, -1, -1):
            if dp[i] == True:
                return i
        return 0
    
    def maxTotalReward3(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        total = rewardValues[-1] * 2
        # dp[v] 能否价格到达v
        dp = [False] * total
        dp[0] = True
        # 前向dp
        for v in rewardValues:
            for i in range(v):
                dp[i + v] |= dp[i]
        for i in range(len(dp) - 1, -1, -1):
            if dp[i] == True:
                return i
        return 0
    
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        f = 1
        for v in sorted(set(rewardValues)):
            # < v 的往前
            f |= (f & ((1 << v) - 1)) << v
        return f.bit_length() - 1
        
# @lc code=end



#
# @lcpr case=start
# [1,1,3,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,6,4,3,2]\n
# @lcpr case=end

#

