/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */
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
class Solution {
 public:
    /*
        怎么简化逻辑怎么来
        1. 本身就是回文串
        2. 删除某个字符变成回文串
    */
    bool checkValid(const char* str, int low, int high, int omit) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (i == omit) {
                ++i;
            } else if (j == omit) {
                --j;
            }
            if (i < j && str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }

    /*
        超时,
        问题 1. 负数和 unsigned int 比较 需要强转
    */
    bool validPalindrome1(string s) {
        for (int i = -1; i < (int)s.size(); ++i) {
            if (checkValid(s.c_str(), 0, s.size() - 1, i)) {
                return true;
            }
        }
        return false;
    }

    /*
        上面算法复杂了, 遍历一次
    */
    int missmatch_count = 0;
    bool validPalindrome(string s) {
        if (s.size() <= 1) {
            return true;
        }
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else {
                ++missmatch_count;
                if (missmatch_count > 1) {
                    return false;
                }
                if (i + 1 < j) {
                    // 左右都匹配递归, 左右都有可能
                    if (s[i] == s[j - 1] && s[i + 1] == s[j]) {
                        // string l1 = s.substr(i, j - i);
                        // string l2 = s.substr(i + 1, j - i);
                        // if (validPalindrome(l1) || validPalindrome(l2)) {
                        //     return true;
                        // }
                        // 检查剩下的是否符合要求即可
                        if (checkValid(s.c_str(), i, j - 1, -1) || checkValid(s.c_str(), i + 1, j, -1)) {
                            return true;
                        }
                        return false;
                    }
                    if (s[i] == s[j - 1]) {
                        --j;
                    } else {
                        // 左右都不匹配
                        ++i;
                    }
                } else {
                    return true;
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main() {
    string s = "aba";
    cout << Solution{}.validPalindrome(s);
}