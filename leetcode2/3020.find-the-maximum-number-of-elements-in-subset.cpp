/*
 * @lc app=leetcode.cn id=3020 lang=cpp
 * @lcpr version=30204
 *
 * [3020] 子集中元素的最大数量
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
    int maximumLength(vector<int>& nums) {
        // 枚举左边界
        //ranges::sort(nums);
        unordered_map<int, int> cnt;
        for (auto v : nums) {
            cnt[v]++;
        }
        int ans = 1;
        unordered_map<int, int> mark;
        for (auto& [k, v]: cnt) {
            if (k == 1) {
                // 奇数个才行
                if (v % 2 == 0) v--;
                ans = max(ans, v);
                continue;
            }
            if (mark[k] or v < 2) continue;
            long long key = k;
            int len = 0;
            while (cnt.count(key) and cnt[key] >= 2 and key <= 1e9) {
                mark[key] = 1;
                len++;
                key *= key;
            }
            if (!cnt.count(key)) ans = max(ans, len * 2 - 1);
            else {
                ans = max(ans, len * 2 + 1);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,4]\n
// @lcpr case=end

 */

