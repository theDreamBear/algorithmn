/*
 * @lc app=leetcode.cn id=3510 lang=cpp
 * @lcpr version=30204
 *
 * [3510] 移除最小数对使数组有序 II
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
    int minimumPairRemoval(vector<int>& nums) {
        // 需求接口文档
        // 1. min 接口
        // 2. 修改pre next
        // 3. delete cur
        // 堆链表
        unordered_set<int> removed;
        unordered_map<int, int> prev, nxt;
        vector<int> sum(nums.size() - 1);
        auto cmp = [&](int lhs, int rhs) {
            if (nums[lhs] != nums[rhs] {
                return sum[lhs] > sum[rhs];
            })
            return lhs > rhs;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int id = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size()) {
                sum[i] = nums[i] + nums[i + 1];
                pq.push(i);
            }
            if (i == 0) {
                prev[i] = -1;
            }
            if (i + 1 == nums.size()) {
                nxt[i] = -1;
            }
            prev[i] = i - 1;
            nxt[i] = i + 1;
        }
        for (;pq.size();) {
            auto i = pq.top();
            pq.pop();
            int
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */

