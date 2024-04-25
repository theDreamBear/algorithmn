/*
 * @lc app=leetcode.cn id=164 lang=cpp
 * @lcpr version=30122
 *
 * [164] 最大间距
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
    void radixSort(vector<int> &nums, int low, int high, int position, int dev) {
        if (low >= high || !position || !dev) {
            return;
        }
        int counting[10]{0};
        vector<int> tmp(high - low + 1);
        memset(counting, 0, sizeof counting);
        for (int i = low; i <= high; i++) {
            int idx = nums[i] / dev % 10;
            counting[idx]++;
        }
        for (int i = 1; i < 10; i++) {
            counting[i] += counting[i - 1];
        }
        int cp[10];
        for (int i = 0; i < 10; i++) {
            cp[i] = counting[i];
        }
        for (int j = high; j >= low; j--) {
            tmp[--counting[nums[j] / dev % 10]] = nums[j];
        }
        for (int i = 0; i < tmp.size(); i++) {
            nums[i + low] = tmp[i];
        }
        for (int i = 0; i < 10; i++) {
            radixSort(nums, i == 0 ? low : cp[i - 1] + low, cp[i] - 1 + low, position - 1, dev / 10);
        }
    }

    int maximumGap(vector<int> &nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int max_val = ranges::max(nums);
        int max_length = 0;
        int dev = 1;
        while (max_val) {
            max_length++;
            max_val /= 10;
            dev *= 10;
        }
        dev /= 10;
        radixSort(nums, 0, nums.size() - 1, max_length, dev);
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        cout << is_sorted(nums.begin(), nums.end()) << endl;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,9,1]\n
// @lcpr case=end

// @lcpr case=start
// [10]\n
// @lcpr case=end

 */

