/*
 * @lc app=leetcode.cn id=3453 lang=cpp
 * @lcpr version=30204
 *
 * [3453] 分割正方形 I
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        // 符合
        double total = 0;
        map<int, int> hs;
        for (auto& vec: squares) {
            double y = vec[1], l = vec[2];
            hs[y] += l;
            hs[y + l] -= l;
            total += l * l;
        }
        double area = 0, s = 0;
        for (auto it = hs.begin();;) {
            double y = it->first, l = it->second;
            s += l;
            double y2 = ((++it)->first);
            area += (y2 - y) * s;
            if (area * 2 >= total) {
                return y2 - (area * 2 - total) / (2 * s);
            }
        }
        return 0;
    }

    double separateSquares2(vector<vector<int>>& squares) {
        // 符合
        sort(squares.begin(), squares.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        double total = 0;
        for (auto& vec: squares) {
            total += ((double)vec[2] * vec[2]);
        }
        total /= 2;
        auto cal = [&](double z) {
            double sum = 0;
            for (auto& vec: squares) {
                double x = vec[0], y = vec[1], l = vec[2];
                if (z < y) {
                    break;
                }
                if (y + l >= z and y <= z) {
                    sum += (l * (z - y));
                    // 正方形完全在下面
                } else if (z >= y + l) {
                    sum += (l * l);
                }
            }
            return sum;
        };
        // 二分
        double low = 0, high = 1e9;
        while (high - low > 1e-6) {
            double mid = (high + low) / 2;
            double sum = cal(mid);
            if (sum < total) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }

    double separateSquares1(vector<vector<int>>& squares) {
        // 符合
        double total = 0;
        double low = 0, high = 1e9;
        for (auto& vec: squares) {
            low = min(low, (double)vec[1]);
            high = max(high, (double)vec[1] + vec[2]);
            total += ((double)vec[2] * vec[2]);
        }
        total /= 2;
        auto cal = [&](double z) {
            double sum = 0;
            for (auto& vec: squares) {
                double x = vec[0], y = vec[1], l = vec[2];
                // z穿过正方形
                if (y + l >= z and y <= z) {
                    sum += (l * (z - y));
                    // 正方形完全在下面
                } else if (z >= y + l) {
                    sum += (l * l);
                }
            }
            return sum;
        };
        // 二分
        while (high - low > 1e-6) {
            double mid = (high + low) / 2;
            double sum = cal(mid);
            if (sum < total) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,1],[2,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,2],[1,1,1]]\n
// @lcpr case=end

 */

