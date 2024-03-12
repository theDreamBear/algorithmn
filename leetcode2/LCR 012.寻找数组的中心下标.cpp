/*
 * @lc app=leetcode.cn id=LCR 012 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 012] 寻找数组的中心下标
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
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int total = prefix.back();
        for (int i = 0; i < nums.size(); i++) {
            if (prefix[i] == total - prefix[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,3,6,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3]\n
// @lcpr case=end

// @lcpr case=start
// [2, 1, -1]\n
// @lcpr case=end

 */

