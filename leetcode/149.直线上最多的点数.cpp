/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
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
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int cnt(int x1, int x2, vector<vector<int>> &points) {
        int ans = 2;
        for (int i = 0; i < points.size(); ++i) {
            if (i == x1 || i == x2) {
                continue;
            }
            if ((points[x1][0] - points[x2][0]) * (points[x1][1] - points[i][1]) ==
                (points[x1][0] - points[i][0]) * (points[x1][1] - points[x2][1])) {
                ++ans;
            }
        }
        return ans;
    }

    int maxPoints1(vector<vector<int>> &points) {
        int ans = 1;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                ans = max(ans, cnt(i, j, points));
                if (ans > points.size() / 2) {
                    break;
                }
            }
        }
        return ans;
    }

    string simplestFractionStr(int m, int n) {
        int gd = gcd(m, n);
        string sign;
        if (m * n < 0) {
            sign = "-";
        }
        return sign + to_string(abs(m / gd)) + "_" + to_string(abs(n / gd));

    }

    string str_slope_ratio(int x1, int y1, int x2, int y2) {
        if (x1 == x2) {
            // 垂直x 轴的只记录 x 其 x 的位置即可
            return to_string(x1);
        }
        int km = x2 * y1 - x1 * y2;
        int kz = x2 - x1;

        int bm = y2 - y1;
        int bz = kz;
        // y = kx + b
        // k, b 均用分式表示
        // k = km / kz 的最简分式 = kms / kzs
        // b = bm / bz 的最简分式 = bms / bzs
        // 最终斜率为 kms_kzs_bms_bzs
        return simplestFractionStr(km, kz) + "_" + simplestFractionStr(bm, bz);
    }

    int maxPoints2(vector<vector<int>> &points) {
        int ans = 1;
        unordered_map<string, unordered_set<int>> hash_map;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string ratio = str_slope_ratio(points[i][0], points[i][1], points[j][0], points[j][1]);

                hash_map[ratio].insert(i);
                hash_map[ratio].insert(j);
                if (hash_map[ratio].size() > ans) {
                    ans = hash_map[ratio].size();
                }
            }
        }
        return ans;
    }

    static constexpr int JIN = 2e4 + 1;

    int int_slope_ratio(int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        if (dx == 0) {
            dy = 1;
        } else if (dy == 0) {
            dx = 1;
        } else {
            if (dy < 0) {
                dx = -dx;
                dy = -dy;
            }
            int gcdXy = gcd(dx, dy);
            dx /= gcdXy;
            dy /= gcdXy;
        }
        return dx * JIN + dy;
    }


   int maxPoints(vector<vector<int>> &points) {
        int ans = 1;
        for (int i = 0; i < points.size(); ++i) {
            if (ans > points.size() / 2 || ans >= points.size() - i) {
                break;
            }
            unordered_map<int, int> hash_map;
            for (int j = i + 1; j < points.size(); ++j) {
                int ratio = int_slope_ratio(points[i][0], points[i][1], points[j][0], points[j][1]);
                if (++hash_map[ratio] + 1 > ans) {
                    ans = hash_map[ratio] + 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

