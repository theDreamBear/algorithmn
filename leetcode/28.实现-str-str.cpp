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

#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
constexpr unsigned int primeRK = 16777619;

unsigned int quickMi(unsigned int base, int n) {
    unsigned int ans = 1;
    while (n) {
        if (n & 0x1) {
            ans *= base;
        }
        base *= base;
        n >>= 1;
    }
    return ans;
}

void hashStr(const string &s, unsigned int &hash) {
    hash = 0;
    for (auto c : s) {
        hash = (hash * primeRK) + c;
    }
    return;
}

bool strcmp(const char *source, const char *target, int p1, int p2, int n) {
    for (int i = 0; i < n; i++) {
        if (source[p1++] != target[p2++]) {
            return false;
        }
    }
    return true;
}

int indexRabinKarp(const string &source, const string &target) {
    if (source.size() < target.size()) {
        return -1;
    }
    int n = target.size();
    unsigned int tHash, p;
    hashStr(target, tHash);
    p = quickMi(primeRK, target.size());

    unsigned int h;
    hashStr(source.substr(0, target.size()), h);
    if (tHash == h && strcmp(source.c_str(), target.c_str(), 0, 0, n)) {
        return 0;
    }
    int i = 0;
    while (i + n < source.size()) {
        h = h * primeRK + source[i + n];
        h -= (p * source[i]);
        i++;
        if (tHash == h && strcmp(source.c_str(), target.c_str(), i, 0, n)) {
            return i;
        }
    }
    return -1;
}

class Solution1 {
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

    int strStr4(string haystack, string needle) {
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
            } else {
                // i + nSize 下标越界判断,
                // 这步可以不用,但是这是利用了字符串最后有一个'\0'的原因
                if (i + nSize == hSize) {
                    break;
                }
                int n = sun.next(i + nSize);
                i = i + nSize - n;
                j = 0;
            }
        }
        return -1;
    }

    void makeNext(const char* target, int* next) {
        int tn = strlen(target);
        next[0] = -1;
        fill(next + 1, next + tn, 0);
        for (int i = 0; i < tn; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                string left = (string(target, j + 1));
                string right = string(target + i - j, j + 1);
                if (left == right) {
                    next[i + 1] = j + 1;
                    break;
                }
            }
        }
        for (int i = 0; i < tn; ++i) {
            cout << next[i] << " " << endl;
        }
        return;
    }

    void makeNext2(const string& target, vector<int>& next) {
        next = vector<int>(target.size(), 0);
        int k = 0;
        for (int i = 1; i < target.size(); ++i) {
            while (k > 0 && target[k] != target[i]) {
                k = next[k - 1];
            }
            if (target[k] == target[i]) {
                ++k;
            }
            next[i] = k;
        }
    }

    /*
     *  找目标字符串在 source中匹配的位置
     *
     * */
    int strStrK(const string& source, const string& target, vector<int> next) {
        int j = 0;
        for (int i = 0; i < source.size();) {
            while (j > 0 && source[i] != target[j]) {
                j = next[j - 1];
            }
            if (source[i] == target[j]) {
                ++j;
                ++i;
                if (j == target.size()) {
                    return i - target.size();
                }
            } else {
                ++i;
            }
        }
        return -1;
    }

    vector<int> makeNext(const string& target) {
        vector<int> next = vector<int>(target.size(), 0);
        int k = 0;
        for (int i = 1; i < target.size(); ++i) {
            while (k > 0 && target[k] != target[i]) {
                k = next[k - 1];
            }
            if (target[k] == target[i]) {
                ++k;
            }
            next[i] = k;
        }
        return next;
    }

    int kmp(const string& target, const string& pattern) {
        auto next= makeNext(pattern);
        int k = 0;
        for (int i = 0; i < target.size(); i++) {
            while (k > 0 && target[i] != pattern[k]) {
                k = next[k - 1];
            }
            if (target[i] == pattern[k]) {
                if (++k == pattern.size()) {
                    return i - (int)pattern.size() + 1;
                }
            }
        }
        return -1;
    }

    // 暴力 kmp
    int strStr5(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> nNext;
        makeNext2(needle, nNext);
        return strStrK(haystack, needle, nNext);
    }

        // 暴力 kmp
    int strStr(string haystack, string needle) {
        //return indexRabinKarp(haystack, needle);
        return kmp(haystack, needle);
    }
};

class Sunday {
public:
    const string& needle;
    int mp[300];

    Sunday(const string& needle) : needle(needle) {
        fill(mp, mp + 300, -1);
        for (int i = 0; i < needle.size(); i++) {
            mp[needle[i]] = i;
        }
    }
    int advance(char c) {
        int n = mp[c];
        return (int)needle.size() - n;
    }

    void advance(int& i, int &j, char c) {
        i += advance(c);
        j = 0;
    }

    int strstr(const string& target) {
        int i = 0, j = 0;
        while (i + needle.size() < target.size() + 1) {
            if (needle[j] == target[i + j]) {
                if (++j == needle.size()) {
                    return i;
                }
            } else {
                advance(i, j, target[i + needle.size()]);
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        Sunday sun(needle);
        return sun.strstr(haystack);
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.strStr("aa", "ab");
}