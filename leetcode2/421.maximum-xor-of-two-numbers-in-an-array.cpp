/*
 * @lc app=leetcode.cn id=421 lang=cpp
 * @lcpr version=30204
 *
 * [421] 数组中两个数的最大异或值
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
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int cnt = 0;
            int newans = ans << 1 | 1;
            ans <<= 1;
            unordered_set<int> seen;
            for (auto v: nums) {
                if (seen.contains(v >> i ^ newans)) {
                    ans = newans;
                    break;
                }
                seen.insert(v >> i);
            }
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
// [14,70,53,83,49,91,36,80,92,51,66,70]\n
// @lcpr case=end

 */

