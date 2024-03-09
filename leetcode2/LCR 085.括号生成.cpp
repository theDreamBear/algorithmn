/*
 * @lc app=leetcode.cn id=LCR 085 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 085] 括号生成
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
    void generateParenthesis(vector<string>& ans, string& tmp, int left, int right, int total) {
        if (left > total || right > total) {
            return;
        }
        if (left == total and right == total) {
            ans.push_back(tmp);
            return;
        }
        if (left == total) {
            string suffix(total - right, ')');
            ans.push_back(tmp + suffix);
            return;
        }
        tmp.push_back('(');
        generateParenthesis(ans, tmp, left + 1, right, total);
        tmp.pop_back();

        if (left > right) {
            tmp.push_back(')');
            generateParenthesis(ans, tmp, left, right + 1, total);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        generateParenthesis(ans, tmp, 0, 0, n);
        return ans;
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

