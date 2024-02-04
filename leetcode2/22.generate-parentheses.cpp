/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30114
 *
 * [22] 括号生成
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool valid(const string& str) {
        int lt = 0, rt = 0;
        for (char ch : str) {
            if (ch == '(') {
                lt++;
            } else if (++rt > lt) {
                return false;
            }
        }
        return true;
    }

    // 迭代生成
    // 问题很多
    vector<string> generateParenthesis_iterator(int n) {
        if (n == 0) {
            return {};
        }
        unordered_set<string> exists;
        vector<string> ans;
        int ct = 0;
        queue<string> q;
        q.emplace("");
        while (ct < n) {
            ct++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto str = q.front();
                q.pop();
                for (int left = 0; left <= str.size(); left++) {
                    string ns = str;
                    ns.insert(left, "(");
                    for (int right = left + 1; right <= ns.size(); right++) {
                        string nns = ns;
                        nns.insert(right, ")");
                        if (exists.count(nns)) {
                            continue;
                        }
                        if (valid(nns)) {
                            exists.insert(nns);
                            if (ct == n) {
                                ans.push_back(nns);
                            } else {
                                q.push(nns);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }

    void backtrack(vector<string>& exist, int lt, int rt, string& tmp, const int max_cnt) {
        if (lt + rt >= 2 * max_cnt) {
            exist.push_back(tmp);
            return;
        }
        // 这个地方"()"有问题, ch最后会等于'\0'
        // 需要改成 string("()");
        // for (auto ch : string("()")) {
        //     if (lt < max_cnt) {
        //         if (ch == '(') {
        //             tmp.push_back(ch);
        //             backtrack(exist, lt + 1, rt, tmp, max_cnt);
        //             tmp.pop_back();
        //         } else if (lt > rt) {
        //             tmp.push_back(ch);
        //             backtrack(exist, lt, rt + 1, tmp, max_cnt);
        //             tmp.pop_back();
        //         }
        //     } else if (ch == ')') {
        //         // 后面全部给)
        //         int cnt = max_cnt - rt;
        //         string str(cnt, ')');
        //         exist.push_back(tmp + str);
        //     }
        // }
        if (lt == max_cnt) {
            int cnt = max_cnt - rt;
            string str(cnt, ')');
            exist.push_back(tmp + str);
            return;
        }
        tmp.push_back('(');
        backtrack(exist, lt + 1, rt, tmp, max_cnt);
        tmp.pop_back();

        if (lt > rt) {
            tmp.push_back(')');
            backtrack(exist, lt, rt + 1, tmp, max_cnt);
            tmp.pop_back();
        }
        return;
    }

    // 这种 dfs 思想更加简洁
    void dfs(vector<string>& exist, int left, int right, string tmp) {
        if (left < 0 || left > right) {
            return;
        }
        if (left == 0 && right == 0) {
            exist.push_back(tmp);
            return;
        }
        dfs(exist, left - 1, right, tmp + '(');
        dfs(exist, left, right - 1, tmp + ')');
    }

    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }
        // 回溯生成
        vector<string> exist;
        string tmp;
        dfs(exist, n, n, "");
        return exist;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

