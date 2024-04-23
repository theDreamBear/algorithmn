// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30122
 *
 * [31] 下一个排列
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    void nextPermutation1(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
        return;
    }

    void nextPermutation2(vector<int>& nums) {
        int n = nums.size();
        int pos = n - 1;
        multiset<int> pre;
        while (pos >= 0) {
            pre.insert(nums[pos]);
            if (pos == 0) {
                break;
            }
            if (nums[pos - 1] >= nums[pos]) {
                pos--;
                continue;
            }
            int v = nums[pos - 1];
            auto it = pre.upper_bound(v);
            nums[pos - 1] = *it;
            pre.erase(it);
            pre.insert(v);
            break;
        }
        auto it = pre.begin();
        for (int i = pos; i < n; i++) {
            nums[i] = *it++;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // pos指向递增序列的最后一个
        int pos = n - 1;
        while (pos > 0 and nums[pos - 1] >= nums[pos]) pos--;
        if (pos > 0) {
            // nums[pos] < nums[pos + 1];
            int sz = n - pos;
            auto it = upper_bound(nums.rbegin(), nums.rbegin() + sz, nums[pos - 1]);
            swap(nums[pos - 1], *it);
        }
        for (int i = pos, j = n - 1; i < j; i++, j--){
            swap(nums[i], nums[j]);
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */

