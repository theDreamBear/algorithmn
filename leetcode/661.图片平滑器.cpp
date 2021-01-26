/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    int smoothAvg(const vector<vector<int>>& M, int x, int y) {
        int sum = 0;
        int ct = 0;
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                int xx = x + i;
                int yy = y + j;
                if (xx < 0 || xx >= M.size() || y < 0 || yy >= M[xx].size()) {
                    continue;
                }
                ++ct;
                sum += M[xx][yy];
            }
        }
        return sum / ct;
    }

    vector<vector<int>> imageSmoother1(vector<vector<int>>& M) {
        vector<vector<int>> ans = M;
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M[i].size(); ++j) {
                ans[i][j] = smoothAvg(M, i, j);
            }
        }
        return ans;
    }

    void preprocessing(const vector<vector<int>>& M, vector<vector<int>>& sum) {
        if (M.size() == 0) {
            return;
        }
        int s = 0;
        for (int i = 0; i < M.size(); ++i) {
            s += M[i][0];
            sum[i][0] = s;
        }
        s = 0;
        for (int i = 0; i < M[0].size(); ++i) {
            s += M[0][i];
            sum[0][i] = s;
        }

        for (int i = 1; i < M.size(); ++i) {
            for (int j = 1; j < M[i].size(); ++j) {
                sum[i][j] =
                    sum[i - 1][j] + sum[i][j - 1] + M[i][j] - sum[i - 1][j - 1];
            }
        }
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans = M;
        vector<vector<int>> sum(M.size(), vector<int>(M[0].size()));
        preprocessing(M, sum);
        int rows = M.size();
        int cols = M[0].size();
        // 下标越界问题
        return ans;
    }
};
// @lc code=end
