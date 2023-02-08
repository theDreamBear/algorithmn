#
# @lc app=leetcode.cn id=409 lang=python3
#
# [409] 最长回文串
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dt = {}
        for v in s:
            if v in dt:
                dt[v] += 1
            else:
                dt[v] = 1
        ans = 0
        extra = 0
        for k, v in dt.items():
            if v % 2 != 0:
                extra = 1
                v -= 1
            ans += v
        return ans + extra
# @lc code=end

