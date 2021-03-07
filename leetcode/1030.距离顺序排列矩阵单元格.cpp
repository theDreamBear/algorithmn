/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int getManhatonDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> q;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                int v = i * C + j;
                int d = getManhatonDistance(i, j, r0, c0);
                q.push({d, v});
            }
        }
        while(!q.empty()) {
            auto p = q.top();
            q.pop();
            int i = p.second / C;
            int j = p.second % C;
            ans.push_back({i, j});
        }
        return ans;
    }
};
// @lc code=end

