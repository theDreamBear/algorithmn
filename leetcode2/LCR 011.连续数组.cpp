/*
 * @lc app=leetcode.cn id=LCR 011 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 011] 连续数组
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
    int findMaxLength_暴力(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int ct = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == 0) {
                    ++ct;
                } else {
                    --ct;
                }
                if (ct == 0) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }

    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int pre = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                ++pre;
            } else {
                --pre;
            }
            if (mp.count(pre)) {
                ans = max(ans, i - mp[pre]);
                continue;
            }
            mp[pre] = i;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

 */

