/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30204
 *
 * [93] 复原 IP 地址
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
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> nums;
        auto bt = [&](auto&& dfs, int i) {
            // 边界
            if (i >= s.size() or nums.size() >= 4 
                              or (s.size() - i < 4 - nums.size()) 
                              or (s.size() - i) > 3 * (4 - nums.size())) {
                if (i >= s.size() and nums.size() == 4) {
                    string ip = to_string(nums[0]) + "." + to_string(nums[1]) + "." + to_string(nums[2]) + "." + to_string(nums[3]);
                    ans.push_back(move(ip));
                }
                return;
            }
            for (int j = i, val = 0; j < s.size() and val <= 255; j++) {
                val = val * 10 + (s[j] - '0');
                if (val <= 255) {
                    nums.push_back(val);
                    dfs(dfs, j + 1);
                    nums.pop_back();
                    // 为0的特殊情况
                    if (val == 0) {
                        return;
                    }
                }
            }
        };
        bt(bt, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */

