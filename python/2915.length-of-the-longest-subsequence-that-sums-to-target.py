#
# @lc app=leetcode.cn id=2915 lang=python3
# @lcpr version=30204
#
# [2915] 和为目标值的最长子序列的长度
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
def zeroonepack_exact_max(nums, target, c = None):
    n = len(nums)
    dp = [0] + [-inf] * target
    for v in nums:
        for i in range(target, v - 1, -1):
            dp[i] = max(dp[i], dp[i - v] + 1 if c == None else c[i])
    return dp[target] 

class Solution:
    def lengthOfLongestSubsequence1(self, nums: List[int], target: int) -> int:
        @cache
        def dfs(i : int, j: int):
            if i >= len(nums):
                return 0 if j == 0 else -inf
            # 选
            if j < nums[i]:
                return dfs(i + 1, j)
            return max(dfs(i + 1, j), dfs(i + 1, j - nums[i]) + 1)
        ans = dfs(0, target)
        dfs.cache_clear()
        return ans if ans != -inf else -1
    
    def lengthOfLongestSubsequence2(self, nums: List[int], target: int) -> int:
        dp = [-1] * (target + 1)
        dp[0] = 0
        for x in nums:
            for j in range(target - x, -1, -1):
                if dp[j] >= 0 and dp[j + x] < dp[j] + 1:
                    dp[j + x] = dp[j] + 1
        return dp[target]
    
    def lengthOfLongestSubsequence3(self, nums: List[int], target: int) -> int:
        # 初始化为0 会影响最终结果， 所以不能为0
        # 和恰好等于目标和的最大长度， 其他几个非法， 所以不能为0
        # 每一个值代表长度， 并不是True False, 不存在-1， 所以需要用-inf
        dp = [-inf] * (target + 1)
        dp[0] = 0
        for x in nums:
            for j in range(target, x - 1, -1):
                if dp[j] < dp[j - x] + 1:
                    dp[j] = dp[j - x] + 1

        return dp[-1] if dp[-1] != -inf else -1
    
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        res = zeroonepack_exact_max(nums, target) 
        return -1 if res == -inf else res
        
# @lc code=end



#
# @lcpr case=start
# [1,2,3,4,5]\n9\n
# @lcpr case=end

# @lcpr case=start
# [4,1,3,2,1,5]\n7\n
# @lcpr case=end

# @lcpr case=start
# [1,1,5,4,5]\n3\n
# @lcpr case=end

#

