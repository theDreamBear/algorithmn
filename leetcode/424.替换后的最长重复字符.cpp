/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
        1. 看数据量, 可以推测, 时间复杂度必须在 nlgn 或者 n 才行, 可能 n^2也行

        错误解法: s[i]结尾的最大重读长度
        错误原因  s[i]可能需要改变成别的字符
    */
    int characterReplacement_wrong(string s, int k) {
        if (s.size() <= 1) {
            return s.size();
        }
        int maxLen = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            int j = i;
            int len = 0;
            int left = k;
            while (j >= 0 && s[j] == s[i]) {
                --j;
            }
            len += (i - j);
            int l = j;
            for (; l >= 0; --l) {
                if (s[l] != s[i] && left > 0) {
                    --left;
                    continue;
                }
                if (s[l] != s[i]) {
                    break;
                }
            }
            len += (j - l);
            if (len > maxLen) {
                maxLen = len;
            }
        }
        return maxLen;
    }

    int characterReplacementHelper(const string& s, int k, char c) {
        int maxLen = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            int j = i;
            int len = 0;
            int left = k;
            while (j >= 0 && s[j] == c) {
                --j;
            }
            len += (i - j);
            int l = j;
            for (; l >= 0; --l) {
                if (s[l] != c && left > 0) {
                    --left;
                    continue;
                }
                if (s[l] != c) {
                    break;
                }
            }
            len += (j - l);
            if (len > maxLen) {
                maxLen = len;
            }
        }
        return maxLen;
    }

    /*
        由 1 的错误解法得出灵感的解法
        超时, 复杂度为 上界26n^2
    */
    int characterReplacement_timeout(string s, int k) {
        if (s.size() <= 1) {
            return s.size();
        }
        int maxLen = 0;
        for (int i = 0; i < 26; ++i) {
            char c = 'A' + i;
            int len = characterReplacementHelper(s, k, c);
            if (len > maxLen) {
                maxLen = len;
            }
        }
        return maxLen;
    }

    int characterReplacement(string s, int k) {
        if (s.size() <= 1) {
            return s.size();
        }
        
    }
};
// @lc code=end

int main() {
    string s = "ABABBBA";
    int k = 1;
    cout << Solution{}.characterReplacement(s, k);
}
