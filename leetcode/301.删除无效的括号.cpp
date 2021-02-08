// @before-stub-for-debug-begin
#include <vector>
#include <string>

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
    int min_removed = INT_MAX;
    unordered_set<string> hashset;
    vector<string> ans;
    void removeInvalidParenthesesHelper(string des, const string& source,
                                        int left, int right, int pos,
                                        int removed) {
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
            if (left >= right + 1) {
                // 保留
                des.push_back(source[pos]);
                removeInvalidParenthesesHelper(des, source, left, right + 1,
                                               pos + 1, removed);
                // 忽略
                des.pop_back();
                removeInvalidParenthesesHelper(des, source, left, right,
                                               pos + 1, removed + 1);
            } else {
                // 若右比左多则直接忽略忽略
                removeInvalidParenthesesHelper(des, source, left, right,
                                               pos + 1, removed + 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        removeInvalidParenthesesHelper("", s, 0, 0, 0, 0);
        return ans;
    }
};
// @lc code=end

int main() {
    string  s = ")(";
    Solution{}.removeInvalidParentheses(s);
}