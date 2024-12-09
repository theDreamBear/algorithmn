/*
 * @lc app=leetcode.cn id=3030 lang=cpp
 * @lcpr version=30204
 *
 * [3030] 找出网格的区域平均强度
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
    vector<vector<int>> resultGrid1(vector<vector<int>>& image, int threshold) {
        vector<vector<int>> dir{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        // 枚举左上顶点
        int                         m = image.size(), n = image[0].size();
        vector<vector<vector<int>>> nums(m, vector<vector<int>>(n));
        auto                        ans     = image;
        auto                        isRegin = [&](int u, int v) -> pair<bool, int> {
            bool ok  = true;
            int  sum = 0;
            // 左上角的是u v
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int x = i + u, y = j + v;
                    if (x < 0 or x >= m or y < 0 or y >= n) {
                        ok = false;
                        goto end;
                    }
                    sum += image[x][y];
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dir[k][0], ny = y + dir[k][1];
                        if (nx < 0 or nx >= m or ny < 0 or ny >= n or abs(u - nx) >= 3 or abs(v - ny) >= 3 or nx < u or ny < v) {
                            continue;
                        }
                        if (abs(image[x][y] - image[nx][ny]) > threshold) {
                            ok = false;
                            goto end;
                        }
                    }
                }
            }
        end:
            return {ok, sum / 9};
        };
        auto isRegin2 = [&](int u, int v) -> pair<bool, int> {
            bool ok  = true;
            int  sum = 0;
            sum += image[u][v];
            for (int j = 1; j < 3; j++) {
                if (v + j >= n) {
                    ok = false;
                    goto end;
                }
                sum += image[u][v + j];
                if (abs(image[u][v + j] - image[u][v + j - 1]) > threshold) {
                    ok = false;
                    goto end;
                }
            }
            for (int i = 1; i < 3; i++) {
                if (u + i >= m) {
                    ok = false;
                    goto end;
                }
                sum += image[u + i][v];
                if (abs(image[u + i][v] - image[u + i - 1][v]) > threshold) {
                    ok = false;
                    goto end;
                }
            }
            for (int i = 1; i < 3; i++) {
                for (int j = 1; j < 3; j++) {
                    sum += image[u + i][v + j];
                    if (abs(image[u + i - 1][v + j] - image[u + i][v + j]) > threshold) {
                        ok = false;
                        goto end;
                    }
                    if (abs(image[u + i][v + j - 1] - image[u + i][v + j]) > threshold) {
                        ok = false;
                        goto end;
                    }
                }
            }
        end:
            return {ok, sum / 9};
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto [b, sum] = isRegin2(i, j);
                if (b) {
                    for (int x = 0; x < 3; x++) {
                        for (int y = 0; y < 3; y++) {
                            nums[i + x][y + j].push_back(sum);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i][j].size()) {
                    ans[i][j] = 0;
                    int sum   = 0;
                    for (auto v : nums[i][j]) {
                        sum += v;
                    }
                    ans[i][j] = sum / (int)nums[i][j].size();
                }
            }
        }
        return ans;
    }

    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        vector<vector<int>> dir{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        // 枚举左上顶点
        int                 m = image.size(), n = image[0].size();
        vector<vector<int>> pre(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + image[i][j];
            }
        }
        auto querySum = [&](int i, int j) { return pre[i + 3][j + 3] - pre[i][j + 3] - pre[i + 3][j] + pre[i][j]; };
        auto isRegin  = [&](int u, int v) -> bool {
            bool ok = true;
            // 第一行
            for (int j = 1; j < 3; j++) {
                if (v + j >= n) {
                    ok = false;
                    goto end;
                }
                if (abs(image[u][v + j] - image[u][v + j - 1]) > threshold) {
                    ok = false;
                    goto end;
                }
            }
            for (int i = 1; i < 3; i++) {
                if (u + i >= m) {
                    ok = false;
                    goto end;
                }
                if (abs(image[u + i][v] - image[u + i - 1][v]) > threshold) {
                    ok = false;
                    goto end;
                }
            }
            for (int i = 1; i < 3; i++) {
                for (int j = 1; j < 3; j++) {
                    if (abs(image[u + i - 1][v + j] - image[u + i][v + j]) > threshold) {
                        ok = false;
                        goto end;
                    }
                    if (abs(image[u + i][v + j - 1] - image[u + i][v + j]) > threshold) {
                        ok = false;
                        goto end;
                    }
                }
            }
        end:
            return ok;
        };
        vector<vector<int>> ans(m, vector<int>(n)), cnt(m, vector<int>(n));
        for (int i = 0; i + 3 <= m; i++) {
            for (int j = 0; j + 3 <= n; j++) {
                auto b = isRegin(i, j);
                if (b) {
                    int sum = querySum(i, j) / 9;
                    for (int x = 0; x < 3; x++) {
                        for (int y = 0; y < 3; y++) {
                            cnt[i + x][y + j]++;
                            ans[i + x][y + j]+= sum;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (cnt[i][j]) {
                    ans[i][j] /= cnt[i][j];
                } else {
                    ans[i][j] = image[i][j];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[5,6,7,10],[8,9,10,10],[11,12,13,10]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[10,20,30],[15,25,35],[20,30,40],[25,35,45]]\n12\n
// @lcpr case=end

// @lcpr case=start
// [[5,6,7],[8,9,10],[11,12,13]]\n1\n
// @lcpr case=end

 */
