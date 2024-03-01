/*
 * @lc app=leetcode.cn id=LCR 166 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 166] 珠宝的最高价值
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
    int jewelleryValue(vector<vector<int>>& frame) {
        int m = frame.size();
        int n = frame[0].size();
        for (int j = 1; j < n; j++) {
            frame[0][j] += frame[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            frame[i][0] += frame[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                frame[i][j] += max(frame[i - 1][j], frame[i][j - 1]);
            }
        }
        return frame.back().back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

 */

