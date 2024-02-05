/*
 * @lc app=leetcode.cn id=LCR 067 lang=cpp
 * @lcpr version=30115
 *
 * [LCR 067] 数组中两个数的最大异或值
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
    int findMaximumXOR_violate(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int x = nums[i] ^ nums[j];
                ans = max(ans, x);
            }
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,10,5,25,2,8]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

// @lcpr case=start
// [8,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [14,70,53,83,49,91,36,80,92,51,66,70]\n
// @lcpr case=end

 */

