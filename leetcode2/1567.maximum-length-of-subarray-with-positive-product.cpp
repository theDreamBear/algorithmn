/*
 * @lc app=leetcode.cn id=1567 lang=cpp
 * @lcpr version=30204
 *
 * [1567] 乘积为正数的最长子数组长度
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
class status {
public:
    int val;
    status(int val = 0):val(val) {}
    virtual status* run(int v) = 0;

    int getV(){
        return val;
    }
};

class Zero : public status{
public:
    Zero(int v = 0): status(v) {}

    status *run(int v);
};
class Possitive : public status{
public:
    Possitive(int v = 0): status(v) {}

    status *run(int v);
};
class Negative : public status{
public:
    Negative(int v = 0): status(v) {}

    status *run(int v);
};


status *Zero::run(int v) {
    if (v == 0) {
        return this;
    } else if (v > 0) {
        return new Possitive(1);
    }
    return new Negative(1);
}

status * Possitive::run(int v) {
    if (v == 0) {
        return new Zero(0);
    } else if (v > 0) {
        this->val++;
        return this;
    }
    return new Negative(this->val + 1);
}

status * Negative::run(int v) {
    if (v == 0) {
        return new Zero(0);
    } else if (v > 0) {
        this->val++;
        return this;
    }
    return new Possitive(this->val + 1);
}

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // 乘法会变大
        auto handler = [&](int i, int h) -> pair<bool, int> {
            if (i < 0) {
                return {true, 0};
            }
            return {false, 0};
        };
        int n = nums.size();
        int dp[2][2];
        int ft = 0, st = 1;
        auto get_v = [&](int i, int h) {
            if (auto res = handler(i, h); res.first) {
                return res.second;
            }
            return dp[ft][h];
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                dp[st][0] = get_v(i - 1, 0) + 1;
                dp[st][1] = get_v(i - 1, 1) + (get_v(i - 1, 1) != 0);
            } else if (nums[i] < 0) {
                dp[st][0] = get_v(i - 1, 1) + (get_v(i - 1, 1) != 0);
                dp[st][1] = max({get_v(i - 1, 0) + (get_v(i - 1, 0) != 0), 1});
            } else {
                dp[st][0] = 0;
                dp[st][1] = 0;
            }
            ans = max(ans, dp[st][0]);
            swap(st, ft);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,-2,-3,4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,-2,-3,-4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2,-3,0,1]\n
// @lcpr case=end

 */
