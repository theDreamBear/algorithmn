/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 * @lcpr version=30204
 *
 * [1094] 拼车
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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> data(1100);
        for (auto& tri: trips) {
            data[tri[1]] += tri[0];
            data[tri[2]] -= tri[0]; 
        }
        int res = 0;
        for (int i = 0; i < 1100; i++) {
            res += data[i];
            if (res > capacity) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,5],[3,3,7]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,5],[3,3,7]]\n5\n
// @lcpr case=end

 */

