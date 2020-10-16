/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.18%)
 * Likes:    329
 * Dislikes: 0
 * Total Accepted:    111.1K
 * Total Submissions: 283.3K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 *
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle
 * 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 *
 * 示例 1:
 *
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 *
 *
 * 示例 2:
 *
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 *
 *
 * 说明:
 *
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 *
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0
 * 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 *
 */
#include <string.h>

#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
 public:
    int strStr1(string haystack, string needle) {
        // 边界条件
        if (haystack.size() < needle.size() ||
            (haystack.size() == needle.size() && haystack != needle)) {
            return -1;
        }
        if (needle.size() == 0) {
            return 0;
        }
#ifdef STRR
        int indexHay = 0, indexNeddle = 0, haySize = haystack.size(),
            needleSize = needle.size();
        while (indexHay < haySize - needleSize + 1) {
            if (haystack[indexHay] != needle[indexNeddle]) {
                ++indexHay;
                indexNeddle = 0;
            } else {
                ++indexNeddle;
                while (indexNeddle < needleSize) {
                    if (haystack[indexHay + indexNeddle] ==
                        needle[indexNeddle]) {
                        ++indexNeddle;
                    } else {
                        indexNeddle = 0;
                        ++indexHay;
                        break;
                    }
                }
                if (indexNeddle == needleSize) {
                    return indexHay;
                }
            }
        }
        return -1;
#endif
        // sunday字符串匹配法
        int hashmap[300];
        // cout << sizeof(hashmap) << endl;
        for (int i = 0; i < 300; i++) {
            hashmap[i] = -1;
        }
        // 遗漏点 2  memset sizeof 返回的不是字节大小
        // memset(hashmap, -1, sizeof(hashmap));
        // 遗漏点3
        //  memset -1 是不行的
        for (int i = 0; i < needle.size(); ++i) {
            hashmap[needle[i]] = i;
        }
        int needleIndex = 0;
        int haySize = haystack.size();
        int needleSize = needle.size();
        int hayIndex = 0;
        for (; hayIndex + needleSize < haySize + 1;) {
            if (haystack[hayIndex + needleIndex] != needle[needleIndex]) {
                int pos = hashmap[haystack[hayIndex + needleSize]];
                hayIndex = hayIndex + needleSize - pos;
                needleIndex = 0;
            } else {
                ++needleIndex;
                /**
                 *  遗漏点1 终止条件问题
                 * **/
                if (needleIndex == needleSize) {
                    return hayIndex;
                }
            }
        }
        return -1;
    }

    /*
        1. 字符串数组遍历, 使用下标前保证下标至少为0, 即数组长度至少为1
        双重遍历
    */
    int strStr2(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        if (needle.size() == 0) {
            return 0;
        }
        int i = 0, j = 0;
        /*
            下面的代码的前提 1. needle 的 size 不为 0, 因为我们是从 j 是从 0
           开始的, 默认至少为 1
        */
        while (i + j < haystack.size()) {
            if (haystack[i + j] == needle[j]) {
                ++j;
            } else {
                ++i;
                j = 0;
            }
            if (needle.size() <= j) {
                return i;
            }
        }
        return -1;
    }
    struct sunday {
        const string& hayStack;
        const string& needle;
        int mp[300];

        sunday(const string& hayStack, const string& needle)
            : hayStack(hayStack), needle(needle) {
            fill(mp, mp + 300, -1);
            initNext();
        }

        void initNext() {
            for (int i = 0; i < needle.size(); ++i) {
                mp[needle[i]] = i;
            }
        }

        int next(int i) { return mp[hayStack[i]]; }
    };

    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        if (needle.size() == 0) {
            return 0;
        }
        int i = 0, j = 0;
        int hSize = haystack.size();
        int nSize = needle.size();
        /*
            使用 sunday算法加速
        */
        sunday sun(haystack, needle);
        /*
            下面的代码的前提 1. needle 的 size 不为 0, 因为我们是从 j 是从 0
           开始的, 默认至少为 1
        */

        while (i + nSize < hSize + 1) {
            if (haystack[i + j] == needle[j]) {
                ++j;
                if (j == nSize) {
                    return i;
                }
            }  else {
                // i + nSize 下标越界判断, 这步可以不用,但是这是利用了字符串最后有一个'\0'的原因
                if (i + nSize== hSize) {
                    break;
                }
                int n = sun.next(i + nSize);
                i = i + nSize - n;
                j = 0;
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.strStr("aa", "ab");
}