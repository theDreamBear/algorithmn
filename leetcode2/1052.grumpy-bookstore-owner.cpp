/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 * @lcpr version=30122
 *
 * [1052] 爱生气的书店老板
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
#include <ranges>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxSatisfied1(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        for (int idx = 0; idx < customers.size(); idx++) {
            if (grumpy[idx] == 0) {
                ans += customers[idx];
            }
        }
        int max_fix = 0;
        for (int idx = 0; idx < customers.size(); idx++) {
            if (grumpy[idx] == 1) {
                int fix = 0;
                int e = min((int)customers.size(), idx + minutes);
                for (int i = idx; i < e; i++) {
                    if (grumpy[i]) {
                        fix += customers[i];
                    }
                }
                max_fix = max(max_fix, fix);
            }
        }
        return ans + max_fix;
    }

    // 滑动窗口
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0, fix = 0, max_fix = 0;
        int left = 0, right = 0;
        while (right < customers.size()) {
            if (!grumpy[right]) {
                ans += customers[right];
                // 这里窗口会
            } else {
                fix += customers[right];
                while (left + minutes <= right) {
                    if (grumpy[left]) {
                        fix -= customers[left];
                    }
                    ++left;
                }
                max_fix = max(max_fix, fix);
            }
            right++;
        }
        return ans + max_fix;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1,2,1,1,7,5]\n[0,1,0,1,0,1,0,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[0]\n1\n
// @lcpr case=end

 */

