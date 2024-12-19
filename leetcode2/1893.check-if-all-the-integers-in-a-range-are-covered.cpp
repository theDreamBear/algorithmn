/*
 * @lc app=leetcode.cn id=1893 lang=cpp
 * @lcpr version=30204
 *
 * [1893] 检查是否区域内所有整数都被覆盖
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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> data(100);
        for (auto& vec: ranges) {
            data[vec[0]]++;
            data[vec[1] + 1]--;
        }
        int res = 0;
        for (int i = 0; i < left; i++) {
            res += data[i];
        }
        for (int i = left; i <= right; i++) {
            res += data[i];
            if (res <= 0) return false; 
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3,4],[5,6]]\n2\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,10],[10,20]]\n21\n21\n
// @lcpr case=end

 */

