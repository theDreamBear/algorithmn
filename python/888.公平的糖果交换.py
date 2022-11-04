#
# @lc app=leetcode.cn id=888 lang=python3
#
# [888] 公平的糖果交换
#

# @lc code=start
class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        a_sum = sum(aliceSizes)
        b_sum = sum(bobSizes)

        half = (a_sum + b_sum) // 2
        d = a_sum - half
        ans = []
        dt = {}
        for v in bobSizes:
            dt[v] = 1
        for v in aliceSizes:
            if (v - d) in dt:
                ans = [v, v - d]
                break
        return ans
# @lc code=end

