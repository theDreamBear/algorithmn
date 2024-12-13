/*
 * @lc app=leetcode.cn id=2601 lang=cpp
 * @lcpr version=30204
 *
 * [2601] 质数减法运算
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
    bool primeSubOperation(vector<int>& nums) {
        vector<int> isPrime(2001, 1);
        isPrime[0] = isPrime[1] = 0;
        vector<int> pre;
        for (int i = 2; i < 2001; i++) {
            if (isPrime[i]) {
                pre.push_back(i);
                for (int j = i + i; j < 2001; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            int diff = nums[i] - nums[i + 1];
            auto it = upper_bound(pre.begin(), pre.end(), diff) - pre.begin();
            if (pre[it] < nums[i]) {
                nums[i] -= pre[it];
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,9,6,10]\n
// @lcpr case=end

// @lcpr case=start
// [6,8,11,12]\n
// @lcpr case=end

// @lcpr case=start
// [5,8,3]\n
// @lcpr case=end

 */

