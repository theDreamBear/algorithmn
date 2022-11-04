#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#

# @lc code=start
def len_palindrome(s: str, left, right):
    if left < 0 or right >= len(s):
        return 0
    if s[left] != s[right]:
        return 0
    ans = 1
    if left != right:
        ans += 1
    left -= 1
    right += 1
    while left >= 0 and right < len(s):
        if s[left] == s[right]:
            left -= 1
            right += 1
            ans += 2
        else:
            break
    return ans

class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = 0
        left = 0
        right = 0
        for i in range(len(s)):
            oi = len_palindrome(s, i, i)
            ti = len_palindrome(s, i, i + 1)
            if oi > ans:
                ans = oi
                left = i
                right = i
            if ti > ans:
                ans = ti
                left = i
                right = i + 1
        return s[right - ans // 2 :left + ans // 2 + 1]
# @lc code=end

