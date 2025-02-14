/*
 * @lc app=leetcode.cn id=913 lang=cpp
 * @lcpr version=30204
 *
 * [913] 猫和老鼠
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        //
        int n = graph.size();
        vector f(n, vector(n, vector<int>(2, -1)));
        // -1 未访问
        // 3 表示正在访问
        // 1 老鼠胜
        // 2 猫胜
        // 0 平局
        // x 猫的位置, y老鼠的位置
        auto dfs = [&](auto&& dfs, int x, int y, int pick)->int {
            auto& v = f[x][y][pick];
            if (v != -1) {
                return v;
            }
            // 老鼠到了0
            if (y == 0) {
                return v = 1;
            }
            // 猫和老鼠一个地方
            if (x == y) {
                return v == 2;
            }
            if (pick > n * n) {
                return 0;
            }
            v = 3;
            // 老鼠的移动轮次
            if (pick % 2 ==  0) {
                // 如果所有路径都是2, 则猫胜
                int tt = 0;
                for (auto w: graph[y]) {
                    int val = dfs(dfs, x, w, pick + 1);
                    if (val == 3) {
                        tt++;
                        continue;
                    }
                    if (val == 1) {
                        return v = 1;
                    }
                    if (val == 2) {
                        tt++;
                    }
                }
                if (tt == graph[y].size()) {
                    return v = 2;
                }
                return v = 0;
            } else {
                // 猫的移动轮次
                int tt = 0;
                for (auto w: graph[x]) {
                    if (w == 0) {
                        tt++;
                        continue;
                    }
                    int val = dfs(dfs, w, y, pick + 1);
                    if (val == 3) {
                        tt++;
                        continue;
                    }
                    if (val == 2) {
                        return v = 2;
                    }
                    if (val == 1) {
                        tt++;
                    }
                }
                if (tt == graph[x].size()) {
                    return v = 1;
                }
                return v = 0;
            }
        };
        return dfs(dfs, 2, 1, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[0],[3],[0,2]]\n
// @lcpr case=end

 */

