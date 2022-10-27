#
# @lc app=leetcode.cn id=833 lang=python3
#
# [833] 字符串中的查找与替换
#

# @lc code=start
class Solution:
    def findReplaceString1(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        li = []
        for k in range(len(indices)):
            li.append([indices[k], sources[k], targets[k]])
        li.sort(key=lambda x: x[0])
        ans = ""
        i = 0
        idx = 0
        while idx < len(s):
            if i < len(indices) and idx == li[i][0]:
                if s.find(li[i][1], idx) == idx:
                    ans += li[i][2]
                    idx += len(li[i][1])
                i += 1
            else:
                ans += s[idx]
                idx += 1
        return ans

    def findReplaceString(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        li = []
        for k in range(len(indices)):
            li.append([indices[k], sources[k], targets[k]])
        li.sort(key=lambda x: x[0])
        dt = {}
        for item in li:
            dt[item[0]] = [item[1], item[2]]
        ans = ""
        i = 0
        idx = 0
        while idx < len(s):
            if idx in dt:
                item = dt[idx]
                if s.find(item[0], idx) == idx:
                    ans += item[1]
                    idx += len(item[0])
                else:
                    ans += s[idx]
                    idx += 1
            else:
                ans += s[idx]
                idx += 1
        return ans
# @lc code=end

