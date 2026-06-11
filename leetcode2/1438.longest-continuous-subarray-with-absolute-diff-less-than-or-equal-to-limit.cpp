/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 * @lcpr version=30204
 *
 * [1438] 绝对差不超过限制的最长连续子数组
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int longestSubarray1(vector<int>& nums, int limit) {
        // 记录区间的最大值 和最小值
        map<int, int> cnt;
        int left = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ++cnt[nums[i]];
            while (cnt.size() > 1) {
                int mm = cnt.begin()->first;
                int mx = cnt.rbegin()->first;
                if (mx - mm <= limit) {
                    break;
                }
                --cnt[nums[left]];
                if (cnt[nums[left]] == 0) {
                    cnt.erase(nums[left]);
                }
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }

    class Sliding {
        public:
        vector<int>& nums;
        deque<int> mm, mx;
        int left = 0;
        Sliding(vector<int>& nums): nums(nums) {}

        int query() {
            return nums[mx.front()] - nums[mm.front()];
        }

        void push(int i) {
            // 处理mm
            while (mm.size() and nums[i] < nums[mm.back()]) {
                mm.pop_back();
            }
            mm.push_back(i);
            while (mx.size() and nums[i] > nums[mx.back()]) {
                mx.pop_back();
            }
            mx.push_back(i);
        }

        void pop(int limit) {
            assert(!mm.empty() and !mx.empty());
            while (nums[mx.front()] - nums[mm.front()] > limit) {
                if (left == mx.front()) {
                    mx.pop_front();
                }
                if (left == mm.front()) {
                    mm.pop_front();
                }
                ++left;
            }
        }

        int Left() {
            return left;
        }
    };

    int longestSubarray(vector<int>& nums, int limit) {
        Sliding sl(nums);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sl.push(i);
            sl.pop(limit);
            ans = max(ans, i - sl.Left() + 1);
        }
        return ans;
    }

    int longestSubarray2(vector<int>& nums, int limit) {
        // 记录区间的最大值 和最小值
        // mm 单调不减 上
        // mx 单调不增 下
        deque<int> mm, mx;
        int left = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 处理mm
            while (mm.size() and nums[i] < nums[mm.back()]) {
                mm.pop_back();
            }
            mm.push_back(i);
            while (mx.size() and nums[i] > nums[mx.back()]) {
                mx.pop_back();
            }
            mx.push_back(i);
            while (nums[mx.front()] - nums[mm.front()] > limit) {
                if (left == mx.front()) {
                    mx.pop_front();
                }
                if (left == mm.front()) {
                    mm.pop_front();
                }
                ++left;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {8, 2, 4, 7};
    cout << Solution{}.longestSubarray(nums, 4);
}

/*
// @lcpr case=start
// [8,2,4,7]\n4\n
// @lcpr case=end

// @lcpr case=start
// [10,1,2,4,7,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,2,4,4,2,2]\n0\n
// @lcpr case=end

 */

