/*
 * @lc app=leetcode.cn id=3066 lang=cpp
 * @lcpr version=30204
 *
 * [3066] 超过阈值的最少操作数 II
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
    // x >= y, x + 2 * y
    // x < y,  y + x * x;
    //
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq;
        for (auto v: nums) {
            pq.push(v);
        }
        int ans = 0;
        while (!pq.empty() and pq.top() < k) {
            auto x = pq.top(); pq.pop();
            auto y = pq.top(); pq.pop();
            ans++;
            //if ((long long)y + (long long)2 * x < k) {
            pq.push((long long)y + 2 * x);
            //}
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,11,10,1,3]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,4,9]\n20\n
// @lcpr case=end

 */

