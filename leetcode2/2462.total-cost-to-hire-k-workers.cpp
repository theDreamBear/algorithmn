/*
 * @lc app=leetcode.cn id=2462 lang=cpp
 * @lcpr version=30204
 *
 * [2462] 雇佣 K 位工人的总代价
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
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // 一定会全考虑
        if (2 * candidates + k > costs.size()) {
            nth_element(costs.begin(), costs.begin() + k, costs.end());
            return accumulate(costs.begin(), costs.begin() + k, 0LL);
        }
        auto cmp = [&](int i, int j) {
            return costs[i] > costs[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> p(cmp), q(cmp);
        int n = costs.size();
        int i = 0, j = n - 1;
        for (; i < candidates; i++) {
            p.push(i);
        }
        for (int ct = 0; ct < candidates and i <= j; ct++, j--) {
            q.push(j);
        }
        long long ans = 0;
        while (k--) {
            int lv = p.empty() ? INT_MAX : costs[p.top()];
            int rv = q.empty() ? INT_MAX : costs[q.top()];
            if (lv <= rv) {
                ans += lv;
                p.pop();
                if (i <= j) {
                    p.push(i++);
                }
            } else {
                ans += rv;
                q.pop();
                if (i <= j) {
                    q.push(j--);
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [17,12,10,2,7,2,11,20,8]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,1]\n3\n3\n
// @lcpr case=end

 */

