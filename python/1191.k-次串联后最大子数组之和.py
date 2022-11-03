#
# @lc app=leetcode.cn id=1191 lang=python3
#
# [1191] K 次串联后最大子数组之和
#

# @lc code=start
# 整体和大于0
# (K - 1) * sum + sum[0:x]

# 整体和小于 0
# 一个区间中间
# 包括结尾 + 开头最大
def fromPostMax(arr: List[int], start, step, end):
    g_max_val = 0
    max_val = 0
    while start != end:
        max_val += arr[start]
        g_max_val = max(g_max_val, max_val)
        start += step
    return g_max_val

def PostMax(arr: List[int], start, step, end):
    g_max_val = 0
    max_val = 0
    while start != end:
        max_val += arr[start]
        g_max_val = max(g_max_val, max_val)
        start += step
        max_val = max(max_val, 0)
    return g_max_val


class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        beg = fromPostMax(arr, 0, 1, len(arr))
        end = fromPostMax(arr, len(arr) - 1, -1, -1)
        all = sum(arr)
        mid = PostMax(arr, 0, 1, len(arr))
        pz = all
        if k > 1:
            pz = max(all, (k - 2) * max(0, all) + beg + end)
        ans = max(beg, end, all, mid, pz)
        return ans % (10 ** 9 + 7)
# @lc code=end

