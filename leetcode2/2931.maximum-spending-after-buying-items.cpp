/*
 * @lc app=leetcode.cn id=2931 lang=cpp
 * @lcpr version=30204
 *
 * [2931] 购买物品的最大开销
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
    long long maxSpending(vector<vector<int>>& values) {
        auto cmp = [&](pair<int, int>& l, pair<int, int>& r) {
            return values[l.first][l.second] > values[r.first][r.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < values.size(); i++) {
            int j = values[i].size() - 1;
            pq.push({i, j});
        }
        long long ans = 0;
        int d = 1;
        while (!pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();
            if (j) {
                pq.push({i, j - 1});
            }
            ans += (long long)values[i][j] * d++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[8,5,2],[6,4,1],[9,7,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[10,8,6,4,2],[9,7,5,3,2]]\n
// @lcpr case=end

 */

