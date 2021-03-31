/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    bool valid(vector<string>& temp, int x, int y) {
        // 列
        for (int i = 0; i < x; ++i) {
            if (temp[i][y] == 'Q') {
                return false;
            }
        }
        // 45°
        int nx = x - 1, ny = y + 1;
        while (nx >= 0 && ny < temp[0].size()) {
            if (temp[nx][ny] == 'Q') {
                return false;
            }
            nx = nx - 1;
            ny = ny + 1;
        }

        // 135°
        nx = x - 1, ny = y - 1;
        while (nx >= 0 && ny >= 0) {
            if (temp[nx][ny] == 'Q') {
                return false;
            }
            nx = nx - 1;
            ny = ny - 1;
        }
        return true;
    }

    void backtracking(vector<vector<string>>& ans, vector<string>& temp, int row) {
        if (row >= temp.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < temp[0].size(); ++i) {
            if (valid(temp, row, i)) {
                temp[row][i] = 'Q';
                backtracking(ans, temp, row + 1);
                temp[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens1(int n) {
        vector<string> temp(n, string(n, '.'));
        vector<vector<string>> ans;
        backtracking(ans, temp, 0);
        return ans;
    }

    void backtracking_plus(vector<vector<string>>& ans, vector<string>& temp, int i, int now, int ld, int rd, int upperlimt) {
        if (now == upperlimt) {
            ans.push_back(temp);
            return;
        }
        int pos = upperlimt & ~(now | ld | rd);
        while (pos) {
            int p = pos & ~(pos - 1);
            pos -= p;
            int index = log2(p);
            temp[i][index] = 'Q';
            backtracking_plus(ans, temp, i + 1, now ^ p, (ld ^ p) << 1, (rd ^ p) >> 1, upperlimt);
            temp[i][index] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        vector<vector<string>> ans;
        backtracking_plus(ans, temp,0, 0, 0, 0, pow(2, n) - 1);
        return ans;
    }
};
// @lc code=end

int main() {
    auto data = Solution{}.solveNQueens(5);
    for (auto& strvec : data) {
        for (auto& str : strvec) {
            cout << str << endl;
        }
        cout << endl;
    }
}
