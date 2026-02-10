/*
 * @lc app=leetcode.cn id=3719 lang=cpp
 * @lcpr version=30204
 *
 * [3719] 最长平衡子数组 I
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
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            set<int> odd, even;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    even.insert(nums[j]);
                } else odd.insert(nums[j]);
                if (even.size() == odd.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2]\n
// @lcpr case=end

 */

