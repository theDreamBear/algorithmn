/*
 * @lc app=leetcode.cn id=LCR 086 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 086] 分割回文串
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
    bool can(const string& s, int low, int high) {
        if (low > high) {
            return false;
        }
        if (low == high) {
            return true;
        }
        for (; low < high; low++, high--) {
            if (s[low] != s[high]) {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<vector<string>>& ans, vector<string>& cur, const string& s, int pos) {
        if (pos >= s.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = pos; i < s.size(); i++) {
            if (can(s, pos, i)) {
                string tmp = s.substr(pos, i - pos + 1);
                cur.push_back(tmp);
                backtrack(ans, cur, s, i + 1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition1(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        backtrack(ans, cur,  s, 0);
        return ans;
    }

    void backtrack(vector<vector<string>>& ans, vector<string>& cur, const string& s, int pos, const vector<vector<int>>& dp) {
        if (pos >= s.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = pos; i < s.size(); i++) {
            if (dp[pos][i]) {
                string tmp = s.substr(pos, i - pos + 1);
                cur.push_back(tmp);
                backtrack(ans, cur, s, i + 1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int left = i, right = i;
            while (left >= 0 and right < n and s[left] == s[right]) {
                dp[left][right] = 1;
                --left;
                ++right;
            }
            left = i - 1, right = i;
            while (left >= 0 and right < n and s[left] == s[right]) {
                dp[left][right] = 1;
                --left;
                ++right;
            }
        }
        vector<string> cur;
        backtrack(ans, cur,  s, 0, dp);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "google"\n
// @lcpr case=end

// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

