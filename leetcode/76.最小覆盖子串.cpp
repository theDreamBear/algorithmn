/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:

    /*
        暴力搜索
        时间复杂度O(n^3)

    */
    string minWindow_bad(string s, string t) {
        map<char, int> source;
        for (auto& c : t) {
            ++source[c];
        }
        int left = -1, ans = -1;
        for (int j = 0; j < s.size(); ++j) {
            for (int i = 0; i <= j; ++i) {
                map<char, int> temp = source;
                int needed = source.size();
                for (int k = i; k <= j; ++k) {
                    if (--temp[s[k]] == 0) {
                        --needed;
                    }
                }
                if (needed == 0) {
                    if (left == - 1 || ans > j - i + 1) {
                        left = i;
                        ans = j - i + 1;
                    }
                }
            }
        }
        if (left == -1) {
            return "";
        }
        return s.substr(left, ans);
    }

    /*
        int left = -1, ans = INT_MAX;
        int p = 0, i = 0

        [p, i) 正在处理区间
        [i, len) 待处理区间

        循环不变式：
        开始时： 成立
        结束时： 
    */

    string minWindow(string s, string t) {
        int left = -1, ans = INT_MAX;
        int p = 0, i = 0, len = s.size();
        map<char, int> source;
        for (auto& c : t) {
            ++source[c];
        }
        map<char, int> temp;
        int needed = source.size();
        while (i < len) {
            if (needed > 0) {
                if (++temp[s[i]] == source[s[i]]) {
                    --needed;
                }
                ++i;
                while (needed == 0) {
                    if (ans > i - p) {
                        ans = i - p;
                        left = p;
                    }
                    // 先处理，再++
                    if (--temp[s[p]] < source[s[p]]) {
                        ++needed;
                    }
                    ++p;
                }
            }
        }
        if (ans == INT_MAX) {
            return "";
        }
        return s.substr(left, ans);
    }
};
// @lc code=end


int main() {
    string s = "acbbaca", t = "aba";
    cout << Solution{}.minWindow(s, t) << endl;
}