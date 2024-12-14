/*
 * @lc app=leetcode.cn id=2588 lang=cpp
 * @lcpr version=30204
 *
 * [2588] 统计美丽子数组数目
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
    // 
    long long beautifulSubarrays(vector<int>& nums) {
        // 整个异或等于0
        // logtric;
        unordered_map<int, int> ct;
        ct[0] = 1;
        long long ans = 0;
        int val = 0;
        for (auto v : nums) {
            val ^= v;
            if (ct.contains(val)) {
                ans += ct[val];
            }
            ct[val]++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,4]\n
// @lcpr case=end

 */

