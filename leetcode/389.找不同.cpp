/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (60.16%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    19.8K
 * Total Submissions: 32.8K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * s = "abcd"
 * t = "abcde"
 * 
 * 输出：
 * e
 * 
 * 解释：
 * 'e' 是那个被添加的字母。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
/**
 *  1. 统计
 * 
 * 
 * 
 * ***/
    char findTheDifference1(string s, string t) {
        int hashmap[26];
        memset(hashmap, 0, 26 * sizeof(int));
        for (int i = 0; i < t.size(); ++i) {
            ++hashmap[t[i] - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            --hashmap[s[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (hashmap[i] > 0) {
                return i + 'a';
            }
        }
        return 'a';
    }

    /**
     *  相减
     * 
     * **/
    char findTheDifference2(string s, string t) {
        int ans = 0;
        for (auto& x : s) {
            ans -= x;
        }
        for (auto& x : t) {
            ans += x;
        }
        return ans;
    }

    /**
     *  异或
     * 
     * **/
    char findTheDifference(string s, string t) {
        int ans = 0;
        for (auto& x : s) {
            ans ^= x;
        }
        for (auto& x : t) {
            ans ^= x;
        }
        return ans;
    }
};
// @lc code=end

