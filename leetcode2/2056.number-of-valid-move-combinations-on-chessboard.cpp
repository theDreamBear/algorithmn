/*
 * @lc app=leetcode.cn id=2056 lang=cpp
 * @lcpr version=30204
 *
 * [2056] 棋盘上有效移动组合的数目
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
    // 位置有问题
    int countCombinations_bad(vector<string>& pieces, vector<vector<int>>& positions) {
        //  29 * 15 * 15 * 15 = 
        int n = pieces.size();
        auto getAllPosChe = [&](int i, int j)-> vector<pair<int, int>> {
            vector<pair<int, int>> ans;
            for (int k = 0; k < 8; k++) {
                if (k != i) {
                    ans.push_back({k, j});
                }
                if (k != j) {
                    ans.push_back({i, k});
                }
            }
            ans.push_back({i, j});
            return ans;
        };

        vector<vector<int>> dir{{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        auto getAllPosXiang = [&](int i, int j)-> vector<pair<int, int>> {
            vector<pair<int, int>> ans;
            for (int k = 0; k < dir.size(); k++) {
                int x = i + dir[k][0], y = j + dir[k][1];
                while (x >= 0 and x < 8 and y >= 0 and y < 8) {
                    ans.push_back({x, y});
                    x = x + dir[k][0], y = y + dir[k][1];
                }
            }
            ans.push_back({i, j});
            return ans;
        };
        vector<vector<pair<int, int>>> all(n);
        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> pos;
            if (pieces[i] == "rook" || pieces[i] == "queen") {
                pos = getAllPosChe(positions[i][0] - 1, positions[i][1] - 1);
            }
            if (pieces[i] == "bishop" || pieces[i] == "queen") {
                auto res = getAllPosXiang(positions[i][0] - 1, positions[i][1] - 1);
                pos.insert(pos.end(), res.begin(), res.end());
            }
            if (pieces[i] == "queen") {
                pos.pop_back();
            }
            all[i] = move(pos);
        }
        int dp[8][8]{};
        auto dfs = [&](auto&& dfs, int i) {
            if (i >= n) return 1;
            int res = 0;
            for (int j = 0; j < all[i].size(); j++) {
                auto [x, y] = all[i][j];
                if (dp[x][y] == 0) {
                    dp[x][y] = 1;
                    res += dfs(dfs, i + 1);
                    dp[x][y] = 0;
                } else {
                    cout << x << "\t" << y << endl;
                }
            }
            return res;
        };
        return dfs(dfs, 0);
    }

    int countCombinations_bad2(vector<string>& pieces, vector<vector<int>>& positions) {
        //  29 * 15 * 15 * 15 = 
        int n = pieces.size();
        vector<vector<int>> dirx{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        auto getAllPosChe = [&](int i, int j)-> vector<vector<pair<int, int>>> {
            vector<vector<pair<int, int>>> ans;
            for (int k = 0; k < 4; k++) {
                vector<pair<int, int>> pos;
                int x = i + dirx[k][0], y = j + dirx[k][1];
                while (x >= 0 and x < 8 and y >= 0 and y < 8) {
                    pos.push_back({x, y});
                    x = x + dirx[k][0], y = y + dirx[k][1];
                }
                if (pos.size()) {
                    ans.push_back(pos);
                }
            }
            ans.push_back({{i, j}});
            return ans;
        };

        vector<vector<int>> dir{{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        auto getAllPosXiang = [&](int i, int j)-> vector<vector<pair<int, int>>> {
            vector<vector<pair<int, int>>> ans;
            for (int k = 0; k < dir.size(); k++) {
                vector<pair<int, int>> pos;
                int x = i + dir[k][0], y = j + dir[k][1];
                while (x >= 0 and x < 8 and y >= 0 and y < 8) {
                    pos.push_back({x, y});
                    x = x + dir[k][0], y = y + dir[k][1];
                }
                if (pos.size()) {
                    ans.push_back(pos);
                }
            }
            ans.push_back({{i, j}});
            return ans;
        };

        vector<vector<vector<pair<int, int>>>> all(n);
        for (int i = 0; i < n; i++) {
            vector<vector<pair<int, int>>> pos;
            if (pieces[i] == "rook" || pieces[i] == "queen") {
                pos = getAllPosChe(positions[i][0] - 1, positions[i][1] - 1);
            }
            if (pieces[i] == "bishop" || pieces[i] == "queen") {
                auto res = getAllPosXiang(positions[i][0] - 1, positions[i][1] - 1);
                pos.insert(pos.end(), res.begin(), res.end());
            }
            if (pieces[i] == "queen") {
                pos.pop_back();
            }
            all[i] = std::move(pos);
        }
        int dp[8][8]{};
        auto dfs = [&](auto&& dfs, int i) {
            if (i >= n) return 1;
            int res = 0;
            for (int j = 0; j < all[i].size(); j++) {
                for (int k = 0; k < all[i][j].size(); k++) {
                    auto [x, y] = all[i][j][k];
                    if (dp[x][y] == 0) {
                        dp[x][y] = 1;
                        res += dfs(dfs, i + 1);
                        dp[x][y] = 0;
                    } else {
                        break;
                    }

                }
            }
            return res;
        };
        return dfs(dfs, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["rook"]\n[[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// ["queen"]\n[[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// ["bishop"]\n[[4,3]]\n
// @lcpr case=end

// @lcpr case=start
// ["rook","rook"]\n[[1,1],[8,8]]\n
// @lcpr case=end

// @lcpr case=start
// ["queen","bishop"]\n[[5,7],[3,4]]\n
// @lcpr case=end

 */

