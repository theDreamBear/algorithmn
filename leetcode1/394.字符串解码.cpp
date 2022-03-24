/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
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
#include <numeric>

using namespace std;

// @lc code=start
// 递归
// 为什么递归了
// 因为
// 待解码字符串符合 递归定义
// 1. 本身是待解码字符串
// 2. 子串也是待解码字符串
// 3. 待解码字符串的通项为  [az]*([1-9][a-z])*[a-z]*
// 4. 所以把每个 子项解析完 拼接就能得到结果

#define PR cout
class Solution {
 public:
    /* 保证:   1. 至少包括两个字符 start + 2 <= end  最起码[]
     *        2. 第一个字符是[
     *        3. 返回和第一个[ 想匹配的]的位置, 且ans > start
     *        4. 如果找不到返回-1
     * */
    int findEnd(const string &s, int start, int end) {
        if (start + 2 > end) {
            PR << "start + 2 > end" << start << " " << end << endl;
            return -1;
        }
        int l = 0;
        int r = 0;
        int i = start;
        // 第一个字符是'['
        if (i <= end && s[i] == '[') {
            l++;
            i++;
        } else {
            PR << "first char is not [" << endl;
            return -1;
            //throw logic_error("the first char is not [");
        }
        for (; i <= end; ++i) {
            if (s[i] == '[') {
                ++l;
            } else if (s[i] == ']') {
                ++r;
            }
            // 异常情况
            if (l < r) {
                PR << "[ not match" << endl;
                return -1;
                //throw logic_error("the first char is not l < r");
            }
            if (l == r) {
                break;
            }
        }
        return i;
    }

    string decodeStringHelper(const string &s, int start, int end, int times) {
        string ans;
        int i = start;
        while (i <= end) {
            // 非倍数部分直接回收
            if (isalpha(s[i])) {
                ans.push_back(s[i]);
                i++;
                continue;
            }
            // 若出现非字符, 第一个必为数字
            if (!isdigit(s[i])) {
                throw logic_error("s is bad");
            }
            // 解析数字
            int val = 0;
            while (i < end && isdigit(s[i])) {
                val = val * 10 + s[i] - '0';
                i++;
            }
            // 数字后无别异常
            if (i >= end || s[i] != '[') {
                throw logic_error("s is bad");
            }
            int r = findEnd(s, i, end) - 1;
            int l = i + 1;
            if (l <= r) {
                ans += decodeStringHelper(s, l, r, val);
            }
            i = r + 2;
        }
        string temp = ans;
        for (int t = 1; t < times; t++) {
            ans += temp;
        }
        return ans;
    }

    string decodeString(string s) {
        return decodeStringHelper(s, 0, s.size() - 1, 1);
    }
};
// @lc code=end

