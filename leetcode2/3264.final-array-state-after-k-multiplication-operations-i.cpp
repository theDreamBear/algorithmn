/*
 * @lc app=leetcode.cn id=3264 lang=cpp
 * @lcpr version=30204
 *
 * [3264] K 次乘运算后的最终数组 I
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
    vector<int> getFinalState1(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; i++) {
            int idx = 0;
            for (int j = 1; j < nums.size(); j++) {
                if (nums[j] < nums[idx]) {
                    idx = j;
                }
            }
            nums[idx] *= multiplier;
        }
        return nums;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        while (k--) {
            auto [v, idx] = pq.top(); pq.pop();
            pq.push({v * multiplier, idx});
        }
        vector<int> ans(nums.size());
        while (!pq.empty()) {
            auto [v, idx] = pq.top(); pq.pop();
            ans[idx] = v;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3,5,6]\n5\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n3\n4\n
// @lcpr case=end

 */

