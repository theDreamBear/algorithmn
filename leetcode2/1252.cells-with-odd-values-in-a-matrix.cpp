/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 * @lcpr version=30204
 *
 * [1252] 奇数值单元格的数目
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
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        unordered_map<int, int> rows, cols;
        for (auto& vec: indices) {
            int r = vec[0], c = vec[1];
            rows[r]++;
            cols[c]++;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((rows[i] + cols[j]) % 2 == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n3\n[[0,1],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n[[1,1],[0,0]]\n
  
// @lcpr case=end

 */

