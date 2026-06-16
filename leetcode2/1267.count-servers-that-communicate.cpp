/*
 * @lc app=leetcode.cn id=1267 lang=cpp
 * @lcpr version=30204
 *
 * [1267] 统计参与通信的服务器
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int countServers1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m), cols(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                rows[i]++;
                cols[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j] or (rows[i] <= 1 and cols[j] <= 1)) continue;
                ans++;
            }
        }
        return ans;
    }

    class UF{
    public:
        vector<int>& grid;
        vector<int> pa, rk;

        UF(vector<int>& grid, int n): grid(grid), pa(n), rk(n){
            
        }
    };

    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m), cols(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                rows[i]++;
                cols[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j] or (rows[i] <= 1 and cols[j] <= 1)) continue;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]\n
// @lcpr case=end

 */

