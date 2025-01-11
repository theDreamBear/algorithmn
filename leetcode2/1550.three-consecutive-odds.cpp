/*
 * @lc app=leetcode.cn id=1550 lang=cpp
 * @lcpr version=30204
 *
 * [1550] 存在连续三个奇数的数组
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
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] % 2 != 0 and arr[i - 1] % 2 != 0 and arr[i - 2] % 2 != 0) return true;
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,6,4,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,34,3,4,5,7,23,12]\n
// @lcpr case=end

 */

