#
# @lc app=leetcode.cn id=2369 lang=python3
#
# [2369] 检查数组是否存在有效划分
#

# @lc code=start
class Solution:
    def validPartitionViolate(self, nums: List[int]) -> bool:
        if len(nums) == 0:
            return True
        if len(nums) < 2:
            return False
        if len(nums) == 2:
            return nums[0] == nums[1]
        first = nums[0]
        second = nums[1]
        third = nums[2]
        if first == second:
            r1 = self.validPartition(nums[2:])
            if r1:
                return True
            if second == third:
                return self.validPartition(nums[3:])
            return False
        else:
            if first + 1 == second and second + 1 == third:
                return self.validPartition(nums[3:])
            return False

    def validPartition2(self, nums: List[int]) -> bool:
        if len(nums) == 0:
            return True
        cnt = -1
        pre = -1
        for i, v in enumerate(nums):
            if -1 == cnt:
                cnt = 1
                pre = v
            else:
                if pre == v:
                    cnt += 1
                else:
                    if cnt < 2:
                        if pre + 1 != v or i == len(nums) - 1:
                            return False
                        return v + 1 == nums[i + 1] and self.validPartition(nums[i + 2:])
                    if cnt == 2 or v > pre + 1:
                        return self.validPartition(nums[i:])
                    return self.validPartition(nums[cnt - 1:]) or self.validPartition(nums[cnt:])
        return cnt >= 2

    def validPartition3(self, nums: List[int]) -> bool:
        if len(nums) == 0:
            return True
        if len(nums) < 2:
            return False
        if len(nums) == 2:
            return nums[0] == nums[1]

        if nums[0] != nums[1]:
            if nums[0] + 1 != nums[1]:
                return False
            if nums[1] + 1 != nums[2]:
                return False
            return self.validPartition(nums[3:])
        else:
            if nums[2] != nums[0]:
                return self.validPartition(nums[2:])
            cnt = 2
            pre = nums[0]
            data = nums[2:]
            for i, v in enumerate(data):
                if v == pre:
                    cnt += 1
                else:
                    if pre + 1 != v:
                        return self.validPartition(data[i:])
                    return self.validPartition(nums[cnt - 1:]) or self.validPartition(nums[cnt:])
            return cnt >= 2

    #   动态规划
    #   状态定义: 前i个元素是否是有效划分
    #   结果: dp[n]是否为 true
    #   状态转移方程 dp[n] = dp[n - 2] and nums[n - 1] == nums[n - 2] or other
    #   初始化 dp[0] = true dp[1] = false
    def validPartition(self, nums: List[int]) -> bool:
        dp = [False for i in range(len(nums) + 1)]
        dp[0] = True

        for i in range(2, len(nums) + 1):
            idx = i - 1
            if nums[idx] == nums[idx - 1] and dp[i - 2]:
                dp[i] = True
            if dp[i] is False and idx >= 2:
                if nums[idx] == nums[idx - 1]  and nums[idx] == nums[idx - 2]:
                    dp[i] = dp[i - 3]
                if dp[i] is False and nums[idx - 2] + 1 == nums[idx - 1] and nums[idx - 1] + 1 == nums[idx]:
                    dp[i] = dp[i - 3]
        return dp[len(dp) - 1]
# @lc code=end

