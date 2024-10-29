#
# @lc app=leetcode.cn id=2787 lang=python3
# @lcpr version=30204
#
# [2787] 将一个数字表示成幂的和的方案数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:

    
    def numberOfWays(self, n: int, x: int) -> int:
        dp = [1] + [0] * n
        for i in range(1, 301):
            for v in range(n, (i ** x) - 1, -1):
                dp[v] =  (dp[v] + dp[v - (i ** x)]) % 1_000_000_007
        return dp[n]
        
# @lc code=end



#
# @lcpr case=start
# 10\n2\n
# @lcpr case=end

# @lcpr case=start
# 4\n1\n
# @lcpr case=end

#

