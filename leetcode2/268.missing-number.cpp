/*
 * @lc app=leetcode.cn id=268 lang=cpp
 * @lcpr version=30204
 *
 * [268] 丢失的数字
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
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        bitset<10001> bs;
        for (auto v: nums) {
            bs.set(v);
        }
        for (int i = 0; i < 10001; i++) {
            if (!bs.test(i)) return i;
        }
        return 0;
    }

    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for (auto v: nums) ans ^= v;
        int n = nums.size();
        // if (n % 4 == 0) return ans ^ n;
        // if (n % 4 == 1) return ans ^ 1;
        // if (n % 4 == 2) return ans ^ (n + 1);
        // return ans;

        for (int i = n / 4 * 4; i <= n; i++) ans ^= i;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [9,6,4,2,3,5,7,0,1]\n
// @lcpr case=end

 */

