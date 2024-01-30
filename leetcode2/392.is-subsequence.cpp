/*
 * @lc app=leetcode.cn id=392 lang=cpp
 * @lcpr version=30113
 *
 * [392] 判断子序列
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 时间复杂度: len(t) ^ len(s) 是一个非常大的数
    // n^ m
    bool dfs(string s, string t, int si, int ti) {
        if (si >= s.size() && ti >= s.size()) {
            return true;
        }
        if (si >= s.size() || ti >= t.size()) {
            return false;
        }
        bool flag = false;
        for (int i = ti; i < t.size(); i++) {
            if (s[si] != t[i]) {
                continue;
            }
            if (dfs(s, t, si + 1, i + 1)) {
                return true;
            }
        }
        return false;
    }

    bool isSubsequence1(string s, string t) {
        return dfs(s, t, 0, 0);
    }

    /*

    */
    bool dfs2(string s, string t, int si, int ti) {
        if (si >= s.size() && ti >= s.size()) {
            return true;
        }
        if (si >= s.size() || ti >= t.size()) {
            return false;
        }
        int i = ti;
        for (; i < t.size(); i++) {
            if (s[si] != t[i]) {
                continue;
            }
            break;
        }
        // 匹配上了
        if (i < t.size()) {
            if (dfs2(s, t, si + 1, i + 1)) {
                return true;
            }
        }
        return dfs2(s, t, si, i + 1);
    }

    bool isSubsequence2(string s, string t) {
        return dfs2(s, t, 0, 0);
    }

    /*
        备忘录
        时间复杂度O(m * n)
        可以考虑的优化： 1、 map 的pair改成一个整数
    */
    bool dfs(map<pair<int, int>, int>& visited, string s, string t, int si, int ti) {
        if (si >= s.size() && ti >= s.size()) {
            return true;
        }
        if (si >= s.size() || ti >= t.size()) {
            return false;
        }
        if (visited.count({si, ti})) {
            return visited[{si, ti}];
        }
        bool flag = false;
        for (int i = ti; i < t.size(); i++) {
            if (s[si] != t[i]) {
                continue;
            }
            if (dfs(visited, s, t, si + 1, i + 1)) {
                return true;
            }
        }
        return visited[{si, ti}] = false;
    }

    bool isSubsequence3(string s, string t) {
        map<pair<int, int>, int> visited;
        return dfs(visited, s, t, 0, 0);
    }

    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int m = s.size(), n = t.size();
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n"ahbgdc"\n
// @lcpr case=end

// @lcpr case=start
// "axc"\n"ahbgdc"\n
// @lcpr case=end

 */

