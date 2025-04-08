/*
 * @lc app=leetcode.cn id=3396 lang=cpp
 * @lcpr version=30204
 *
 * [3396] 使数组元素互不相同所需的最少操作次数
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
    int minimumOperations(vector<int>& nums) {
        int type = 0, ans = 0;
        map<int, int> count;
        for (auto v: nums) {
            if (++count[v] == 2) {
                type++;
            }
        }
        for (int i = 0; i < nums.size() and type; ) {
            if (i + 3 >= nums.size()) {
                ans++;
                break;
            }
            if (--count[nums[i++]] == 1) {
                type--;
            }
            if (--count[nums[i++]] == 1) {
                type--;
            }
            if (--count[nums[i++]] == 1) {
                type--;
            }
            ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,2,3,3,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [6,7,8,9]\n
// @lcpr case=end

 */

