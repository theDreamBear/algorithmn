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

    class MoveMent{
        public:
        int x, y, dx, dy, step;

        MoveMent(int x, int y, int dx, int dy, int step):x(x), y(y), dx(dx), dy(dy),step(step){}

        bool isCross(MoveMent& other) {
            int x1 = x, y1 = y;
            int x2 = other.x, y2 = other.y;
            for (int i = 0; i < max(step, other.step); i++) {
                if (i < step) {
                    x1 += dx;
                    y1 += dy;
                }
                if (i < other.step) {
                    x2 += other.dx;
                    y2 += other.dy;
                }
                if (x1 == x2 and y1 == y2) return true;
            }
            if (x1 == x2 and y1 == y2) return true;
            return false;
        }
    };

    vector<vector<int>> rook_dire_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> bishop_dire_ = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<vector<int>> queen_dire_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        vector<MoveMent> stk;
        int ans = 0;
        auto isCross = [&](int u) {
            for (int v = 0; v < u; v++) {
                if (stk[u].isCross(stk[v])) {
                    return true;
                }
            }
            return false;
        };

        auto dfs = [&](auto&& dfs, int u) {
            if (u == n) {
                ans++;
                return;
            }
            vector<vector<int>> dire;
            if (pieces[u] == "rook") {
                dire = rook_dire_;
            } else if (pieces[u] == "queen") {
                dire = queen_dire_;
            } else if (pieces[u] == "bishop") {
                dire = bishop_dire_;
            }
            stk.push_back(MoveMent(positions[u][0], positions[u][1], 0, 0, 0));
            if (!isCross(u)) {
                dfs(dfs, u + 1);
            }
            stk.pop_back();
            for (int i = 0; i < dire.size(); i++) {
                int x = positions[u][0], y = positions[u][1];
                int dx = dire[i][0], dy = dire[i][1];
                for (int j = 1; j < 8; j++) {
                    int nx = x + dx * j;
                    int ny = y + dy * j;
                    if (nx < 1 or nx > 8 or ny < 1 or ny > 8) break;
                    stk.push_back(MoveMent(x, y, dx, dy, j));
                    if (!isCross(u)) {
                        dfs(dfs, u + 1);
                    }
                    stk.pop_back();
                }
            }
        };
        dfs(dfs, 0);
        return ans;
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

