/*
 * @lc app=leetcode.cn id=LCR 057 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 057] 存在重复元素 III
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
#include <set>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate_wrong(vector<int>& nums, int k, int t) {
        if (k == 0 || nums.empty()) {
            return false;
        }
        auto smallCmp = [&](int i , int j) {
            return nums[i] > nums[j];
        };
        auto bigCmp = [&](int i , int j) {
            return nums[i] < nums[j];
        };
        priority_queue<int, vector<int>, decltype(smallCmp)> small(smallCmp);
        priority_queue<int, vector<int>, decltype(bigCmp)> big(bigCmp);
        for (int i = 0; i < k; i++) {
            big.push(i);
            small.push(i);
        }
        for (int i = k; i < nums.size(); i++) {
            // 比较
            if (nums[small.top()] - t <= nums[i] and nums[i] <= nums[big.top()] + t) {
                return true;
            }
            // 添加
            small.push(i);
            big.push(i);
            // 删去
            while (small.top() + k <= i) {
                small.pop();
            }
            while (big.top() + k <= i) {
                big.pop();
            }
        }
        return false;
    }

    /*
        问题1、 超时
        问题2、 越界
    */
    bool containsNearbyAlmostDuplicate_brute_force(vector<int>& nums, int k, int t) {
        if (k == 0 || nums.empty()) {
            return false;
        }
        for (int i = 1; i < nums.size(); i++) {
            // 慢的根本
            for (int j = max(0,i - k); j < i; j++) {
                if (abs(nums[j] - nums[i]) <= t) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsNearbyAlmostDuplicate_map(vector<int>& nums, int k, int t) {
        if (k == 0 || nums.empty()) {
            return false;
        }
        set<int> rec;

        for (int i = 0; i < nums.size(); i++) {
            // 查找
            // [nums[i] - t, nums[i] + t]
            //  修正区间 [max(INT_MIN, nums[i] - t), min(INT_MAX, nums[i] + t)]
            //  修正 left = max(INT_MIN + t, nums[i]) - t
            //  修正 right = min(INT_MAX - t, nums[i]) + t
            auto ite = rec.lower_bound(max(INT_MIN + t, nums[i]) - t);
            if (ite != rec.end() and *ite <=  min(INT_MAX - t, nums[i]) + t) {
                return true;
            }
            rec.insert(nums[i]);
            if (i >= k) {
                rec.erase(nums[i - k]);
            }
        }
        return false;
    }

    int getID(int v, long long w) {
        // 0是属于区间0 的, 所有负数需要+1
        return v >= 0 ? v / w : (v + 1) / w - 1;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0 || nums.empty()) {
            return false;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            // 转为long long
            long long v = nums[i];
            int idx = getID(v, t + 1ll);
            if (mp.count(idx)) {
                return true;
            }
            //                         这里可能会溢出所有需要转为long long
            if (mp.count(idx - 1) and v - mp[idx - 1] <= t) {
                return true;
            }
            //                         这里可能会溢出所有需要转为long long
            if (mp.count(idx + 1) and mp[idx + 1] - v <= t) {
                return true;
            }
            mp[idx] = v;
            if (i >= k) {
                mp.erase(getID(nums[i - k], t + 1ll));
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n3\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,5,9,1,5,9]\n2\n3\n
// @lcpr case=end

 */

