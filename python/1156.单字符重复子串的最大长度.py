#
# @lc app=leetcode.cn id=1156 lang=python3
#
# [1156] 单字符重复子串的最大长度
#

# @lc code=start
class Solution:
    # 分析
    # 以第i个字符开头的最大长度
    #
    def maxRepOpt1Helper(self, text: str) -> int:
        if len(text) <= 1:
            return len(text)
        n = len(text)
        max_len = 1
        dt = {}
        for i in range(n):
            c = text[i]
            flag = False
            sl = 1
            right = n
            for j in range(i + 1, n):
                if j == right or text[j] != c and flag:
                    break
                else:
                    if text[j] == c:
                        sl += 1
                    if text[j] != c:
                        found = False
                        # 优先在前面找
                        if c in dt:
                            found = True
                        else:
                            for k in range(n - 1, j, -1):
                                if text[k] == c:
                                    right = k
                                    found = True
                                    break
                        if found:
                            flag = True
                            sl += 1
            max_len = max(max_len, sl)
            dt[c] = 1
        return max_len

    def maxRepOpt1(self, text: str) -> int:
        l1 = self.maxRepOpt1Helper(text)
        l2 = self.maxRepOpt1Helper(text[::-1])
        return max(l1, l2)
# @lc code=end

