/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 * @lcpr version=30204
 *
 * [1679] K 和数对的最大数目
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
    int maxOperations1(vector<int>& nums, int k) {
        //ranges::sort(nums);
        unordered_map<int, int> mv;
        int ans = 0;
        for (auto v: nums) {
            if (mv.count(k - v)) {
                ans++;
                if (--mv[k - v] == 0) {
                    mv.erase(k - v);
                }
            } else {
                mv[v]++;
            }
        }
        return ans;
    }

    int maxOperations(vector<int>& nums, int k) {
        ranges::sort(nums);
        int ans = 0;
        int n = nums.size();
        for (int i = 0, j = n - 1; i < j;) {
            if (nums[i] + nums[j] < k) i++;
            else if (nums[i] + nums[j] > k) j--;
            else {
                ans++;
                i++;
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,1,3,4,3]\n6\n
// @lcpr case=end

 */

