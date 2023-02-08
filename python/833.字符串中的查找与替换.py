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

    def findReplaceString2(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        li = []
        for k in range(len(indices)):
            li.append([indices[k], sources[k], targets[k]])
        li.sort(key=lambda x: x[0])
        dt = {}
        for item in li:
            dt[item[0]] = [item[1], item[2]]
        ans = ""
        idx = 0
        while idx < len(s):
            if idx in dt:
                item = dt[idx]
                if s.find(item[0], idx) == idx:
                    ans += item[1]
                    idx += len(item[0])
                else:
                    idx += 1
            else:
                ans += s[idx]
                idx += 1
        return ans

    def findReplaceString3(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        dt = {}
        for i, v in enumerate(indices):
            dt[v] = [sources[i], targets[i]]

        candidate = {}
        idx = 0
        while idx < len(s):
            if idx in dt and s.find(dt[idx][0], idx) == idx:
                candidate[idx] = [len(dt[idx][0]), dt[idx][1]]
                idx += len(dt[idx][0])
            else:
                idx += 1
        idx = 0
        ans = ""
        while idx < len(s):
            if idx in candidate:
                ans += candidate[idx][1]
                idx += candidate[idx][0]
            else:
                ans += s[idx]
                idx += 1
        return ans

    # 官方方法
    def findReplaceString(self, S, indexes, sources, targets):
        S = list(S)
        for i, x, y in sorted(zip(indexes, sources, targets), reverse = True):
            if all(i+k < len(S) and S[i+k] == x[k] for k in range(len(x))):
                S[i:i+len(x)] = list(y)

        return "".join(S)

# @lc code=end

