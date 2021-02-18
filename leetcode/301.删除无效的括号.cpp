// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
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
        dfs
    */
    int min_removed = INT_MAX;
    unordered_set<string> hashset;
    vector<string> ans;
    void removeInvalidParenthesesHelper(string des, const string& source,
                                        int left, int right, int pos,
                                        int removed) {
        if (removed > min_removed || left < right) {
            // 剪枝
            return;
        }
        if (pos == source.size()) {
            if (left == right && hashset.count(des) == 0) {
                if (removed < min_removed) {
                    hashset.clear();
                    ans.clear();
                    min_removed = removed;
                }
                if (min_removed == removed) {
                    hashset.insert(des);
                    ans.push_back(des);
                }
            }
            return;
        }
        if (source[pos] != '(' && source[pos] != ')') {
            des.push_back(source[pos]);
            removeInvalidParenthesesHelper(des, source, left, right, pos + 1,
                                           removed);
            return;
        }
        if (source[pos] == '(') {
            // 保留
            des.push_back(source[pos]);
            removeInvalidParenthesesHelper(des, source, left + 1, right,
                                           pos + 1, removed);
            // 忽略
            des.pop_back();
            removeInvalidParenthesesHelper(des, source, left, right, pos + 1,
                                           removed + 1);
        } else {
            des.push_back(source[pos]);
            removeInvalidParenthesesHelper(des, source, left, right + 1,
                                           pos + 1, removed);
            // 忽略
            des.pop_back();
            removeInvalidParenthesesHelper(des, source, left, right, pos + 1,
                                           removed + 1);
        }
    }

    bool valid(const string& s) {
        int left = 0, right = 0;
        for (auto& c : s) {
            if (c == '(' || c == ')') {
                if (c == '(') {
                    ++left;
                } else {
                    ++right;
                    if (left < right) {
                        return false;
                    }
                }
            }
        }
        return left == right;
    }

    // bfs
    void bfs(const string& s, vector<string>& ans) {
        queue<string> q;
        unordered_set<string> hashset;
        q.push(s);
        hashset.insert(s);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string cur = q.front();
                q.pop();
                if (valid(cur)) {
                    ans.push_back(cur);
                    continue;
                }
                if (ans.empty()) {
                    for (int k = 0; k < cur.size(); ++k) {
                        if (cur[k] == '(' || cur[k] == ')') {
                            string temp = cur;
                            temp.erase(k + temp.begin());
                            if (hashset.count(temp) == 0) {
                                q.push(temp);
                                hashset.insert(temp);
                            }
                        }
                    }
                }
            }
            if (!ans.empty()) {
                return;
            }
        }
        return;
    }

    vector<string> removeInvalidParentheses3(string s) {
        removeInvalidParenthesesHelper("", s, 0, 0, 0, 0);
        return ans;
    }

    vector<string> removeInvalidParentheses(string s) {
        bfs(s, ans);
        return ans;
    }
};
// @lc code=end

int main() {
    string s = "";
    Solution{}.removeInvalidParentheses(s);
}