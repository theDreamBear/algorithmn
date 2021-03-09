/*
 * @lc app=leetcode.cn id=1275 lang=cpp
 *
 * [1275] 找出井字棋的获胜者
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    bool gameOver(const vector<vector<int>>& matrix, int x, int y, int val) {
        int nx = x - 1, ny = y, ct = 1;
       
       while (nx >= 0 && matrix[nx][ny] == val) {
            --nx;
            ++ct;
        }

        nx = x + 1;
        while (nx < matrix.size() && matrix[nx][ny] == val) {
            ++nx;
            ++ct;
        }
        if (ct >= 3) {
            return true;
        }

        ct = 1;
        nx = x;
        ny = y - 1;
        while (ny >= 0 && matrix[nx][ny] == val) {
            --ny;
            ++ct;
        }
        ny = y + 1;
        while (ny < matrix[0].size() && matrix[nx][ny] == val) {
            ++ny;
            ++ct;
        }
        if (ct >= 3) {
            return true;
        }

        ct = 1;
        nx = x - 1;
        ny = y - 1;
        while (nx >= 0 && ny >= 0 && matrix[nx][ny] == val) {
            --nx;
            --ny;
            ++ct;
        }
        nx = x + 1;
        ny = y + 1;
        while (nx < matrix.size() && ny < matrix[nx].size() && matrix[nx][ny] == val) {
            ++nx;
            ++ny;
            ++ct;
        }
        if (ct >= 3) {
            return true;
        }

        ct = 1;
        nx = x + 1;
        ny = y - 1;
        while (nx < matrix.size() && ny >= 0 && matrix[nx][ny] == val) {
            ++nx;
            --ny;
            ++ct;
        }

        nx = x - 1;
        ny = y + 1;
        while (nx >= 0 && ny < matrix[nx].size() && matrix[nx][ny] == val) {
            --nx;
            ++ny;
            ++ct;
        }

        return ct >= 3;
    }

    /*
        看清楚题目再做题
    */
    string tictactoe(vector<vector<int>>& moves) {
        int left_space = 9;
        vector<vector<int>> matrix(3, vector<int>(3, INT_MAX));
        for (int i = 0; i < moves.size(); ++i) {
            int val = 1;
            if (i % 2 != 0) {
                val = -1;
            }
            int x = moves[i][0];
            int y = moves[i][1];
            matrix[x][y] = val;
            if (gameOver(matrix, x, y, val)) {
                string ans = "A";
                if (i % 2 != 0) {
                    ans  = "B";
                }
                return ans;
            }
            if (--left_space == 0) {
                return "Draw";
            }
        }
        return "Pending";
    }
};
// @lc code=end

