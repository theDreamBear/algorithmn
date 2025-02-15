/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 * @lcpr version=30204
 *
 * [1706] 球会落何处
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
    vector<int> findBall1(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (m == 1) {
            return vector<int>(m, -1);
        }
        vector<pair<int, int>> pos(m);
        for (int i = 0; i < m; i++) {
            pos[i] = make_pair(i, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int y = pos[j].first;
                if (y == -1) {
                    continue;
                }
                if (y == 0) {
                    if (grid[i][y] == -1 or grid[i][y + 1] == -1) {
                        pos[j].first = -1;
                    } else {
                        pos[j].first++;
                    }
                } else if (y + 1 == m) {
                    if (grid[i][y] == 1 or grid[i][y - 1] == 1) {
                        pos[j].first = -1;
                    } else {
                        pos[j].first--;
                    }
                } else {
                    if ((grid[i][y] == 1 and grid[i][y + 1] == -1) or (grid[i][y] == -1 and grid[i][y - 1] == 1)) {
                        pos[j].first = -1;
                    } else {
                        pos[j].first += grid[i][y];
                    }
                }
            }
        }
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++) {
            ans[pos[i].second] = pos[i].first;
        }
        return ans;
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n);
        for (int j = 0; j < n; j++) {
            int pos = j;
            for (auto& row: grid) {
                int d = row[pos];
                pos += d;
                if (pos < 0 or pos >= n or row[pos] != d) {
                    pos = -1;
                    break;
                }
            }
            ans[j] = pos;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]\n
// @lcpr case=end

// @lcpr case=start
// [[-1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]\n
// @lcpr case=end

 */

