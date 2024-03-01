/*
 * @lc app=leetcode.cn id=LCR 167 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 167] 招式拆解 I
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
    int dismantlingAction(string arr) {
        // 两根指针
        // [left, right) 合法区间
        int left = 0, right = 0;
        vector<int> ct(300);
        int ans = 0;
        for (; right < arr.size(); right++) {
            ct[arr[right]]++;
            if (ct[arr[right]] == 0) {
                continue;
            } else if (ct[arr[right]] > 1) {
                ans = max(ans, right - left);
                while (--ct[arr[left]] != 1) {
                    ++left;
                }
                ++left;
            }
        }
        return ans = max(ans, right - left);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "dbascDdad"\n
// @lcpr case=end

// @lcpr case=start
// "KKK"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

