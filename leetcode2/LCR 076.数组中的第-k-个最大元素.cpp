/*
 * @lc app=leetcode.cn id=LCR 076 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 076] 数组中的第 K 个最大元素
 */


// @lcpr-template-start
#include <cstdlib>
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
#include <numeric>
#include <utility>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int findKthLargest1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<>{});
        return nums[k - 1];
    }

    // [low, high]
    int quickSelect_stl(vector<int>& nums, int low, int high, int k) {
        // 不直接取最后一个值， 使用随机取
        int r = random() % (high - low + 1) + low;
        // 移到最末尾
        swap(nums[r], nums[high]);
        // stl partition 没有swap
        auto p = partition(nums.begin() + low, nums.begin() + high + 1, [&](int v) {
            return v > nums[high];
        }) - nums.begin();
        // 这个地方需要交换， 将
        swap(nums[high], nums[p]);
        // 找到指定位置
        if (p + 1 == k) {
            return nums[p];
        }
        if (p + 1 > k) {
            // high 使用p - 1 不能用p，不然可能会死循环
            return quickSelect_stl(nums, low, p - 1, k);
        }
        // 使用p + 1
        return quickSelect_stl(nums, p + 1, high, k);
    }

    int my_partition(vector<int>& nums, int low, int high) {
         // 不直接取最后一个值， 使用随机取
        int r = random() % (high - low + 1) + low;
        // 移到最末尾
        swap(nums[r], nums[high]);
        // [low, p) 符合的
        // [i, high] 待处理的
        int p = low - 1;
        for (int i = low; i < high; i++) {
            if (nums[i] >= nums[high]) {
                ++p;
                swap(nums[p], nums[i]);
            }
        }
        if (++p != high) {
            swap(nums[p], nums[high]);
        }
        return p;
    }

    int quickSelect(vector<int>& nums, int low, int high, int k) {
        int p = my_partition(nums, low, high);
        // 找到指定位置
        if (p + 1 == k) {
            return nums[p];
        }
        if (p + 1 > k) {
            // high 使用p - 1 不能用p，不然可能会死循环
            return quickSelect(nums, low, p - 1, k);
        }
        // 使用p + 1
        return quickSelect(nums, p + 1, high, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

