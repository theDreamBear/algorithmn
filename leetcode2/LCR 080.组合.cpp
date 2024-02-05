/*
 * @lc app=leetcode.cn id=LCR 080 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 080] 组合
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
    void backtrack(vector<vector<int>>& ans, vector<int>& tmp, int pos, int n, int k) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        if (tmp.size() + n - pos + 1 < k) {
            return;
        }
        for (int i = pos; i <= n; i++) {
            tmp.push_back(i);
            backtrack(ans, tmp, i + 1, n, k);
            tmp.pop_back();
        }
        return;
    }

    vector<vector<int>> combine1(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(ans, tmp, 1, n, k);
        return ans;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << n); i++) {
            if (__builtin_popcount(i) != k) {
                continue;
            }
            int v = i;
            vector<int> tmp;
            while (v > 0) {
                int p = __builtin_ctz(v);
                tmp.push_back(p + 1);
                v ^= (1 << p);
            }
            ans.push_back(move(tmp));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

