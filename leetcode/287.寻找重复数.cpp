/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    int findDuplicate_map(vector<int>& nums) {
        int n = nums.size() - 1;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (++hash[nums[i]] == 2) {
                return nums[i];
            }
        }
        return 0;
    }

    int findDuplicate_arr(vector<int>& nums) {
        int n = nums.size() - 1;
        int hash[n + 1];
        memset(hash, 0, (n + 1) * sizeof(int));
        for (int i = 0; i < nums.size(); ++i) {
            if (++hash[nums[i]] == 2) {
                return nums[i];
            }
        }
        return 0;
    }

    int findDuplicate_2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return 0;
    }

    int findDuplicate_binary_search(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += (nums[i] <= mid);
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

    int findDuplicate_slow_fast(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }

    /*
     比特位比较
    */
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        for (int bit = 0; bit < 31; ++bit) {
            int expected = 0;
            int actual = 0;
            for (auto x : nums) {
                actual += ((x >> bit) & 0x1);
            }
            for (int i = 1; i < nums.size(); ++i) {
                expected += ((i >> bit) & 0x1);
            }
            if (actual > expected) {
                ans += ((1 << bit));
            }
        }
        return ans;
    }
};
// @lc code=end
