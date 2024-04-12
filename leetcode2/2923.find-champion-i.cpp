/*
 * @lc app=leetcode.cn id=2923 lang=cpp
 * @lcpr version=30122
 *
 * [2923] 找到冠军 I
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
    int findChampion1(vector<vector<int>>& grid) {
        vector<int> indegree(grid.size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 1) {
                    indegree[j]++;
                }
            }
        }
        auto it = find(indegree.begin(), indegree.end(), 0);
        return it - indegree.begin();
    }

    int findChampion2(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = ((n - 1) * n) >> 1;
        vector<int> indegree(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (++indegree[j] == 1) {
                        ans -= j;
                    }
                }
            }
        }
        return ans;
    }

    /*
        打擂台
    */
    int findChampion(vector<vector<int>> &grid) {
        int ans = 0;
        for (int i = 1; i < grid.size(); i++) {
            if (grid[i][ans]) {
                ans = i;
            }
        }
        return ans;
    }

    // 其他解法
    // 1、i 行的和 == n - 1;
    // 2、j 列的和为0
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,1],[1,0,1],[0,0,0]]\n
// @lcpr case=end

 */

