/*
 * @lc app=leetcode.cn id=LCR 060 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 060] 前 K 个高频元素
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

    vector<int> topKFrequent1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ct = 0, v = 0;
        auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.first > rhs.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
        for (auto val : nums) {
            if (ct == 0 || (ct > 0 and v == val)) {
                v = val;
                ++ct;
            } else {
                if (pq.size() < k) {
                     pq.push({ct, v});
                } else if (pq.size() >= k and pq.top().first < ct) {
                    pq.pop();
                    pq.push({ct, v});
                }
                v = val;
                ct = 1;
            }
        }
        if (pq.size() < k) {
            pq.push({ct, v});
        } else if (pq.size() >= k and pq.top().first < ct) {
            pq.pop();
            pq.push({ct, v});
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

