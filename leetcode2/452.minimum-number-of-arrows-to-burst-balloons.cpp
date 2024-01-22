/*
 * @lc app=leetcode.cn id=452 lang=cpp
 * @lcpr version=30113
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <assert.h>
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
    int findMinArrowShots1(vector<vector<int>> &points) {
        assert(points.size() > 0);
        if (points.size() <= 1) {
            return points.size();
        }
        int ans = 0;
        sort(points.begin(), points.end());
        int pos = 0;
        while (pos < points.size()) {
            ++ans;
            // 从当前位置选一个
            int des = points[pos][1];
            // 找到以这一个为目的，所能消除的最多气球
            int next = pos + 1;
            while (next < points.size()) {
                int nstart = points[next][0];
                int ndes = points[next][1];
                // 断开了
                if (des < nstart) {
                    break;
                }
                next++;
                // 范围更大，一定能被消除
                if (ndes >= des) {
                    continue;
                }
                // 子集，需要收缩
                if (ndes < des) {
                    des = ndes;
                }
            }
            pos = next;
        }
        return ans;
    }

    int findMinArrowShots2(vector<vector<int>> &points) {
        assert(points.size() > 0);
        if (points.size() <= 1) {
            return points.size();
        }
        int ans = 0;
        sort(points.begin(), points.end());
        int pos = 0;

        auto walkFaraway = [&](int des, int next) -> int {
            // 边界
            if (next >= points.size()) {
                return next;
            }
            while (next < points.size()) {
                int nstart = points[next][0];
                int ndes = points[next][1];
                if (nstart > des) {
                    break;
                }
                next++;
                // nstart <= des
                // 子集就不断收缩
                if (ndes < des) {
                    des = ndes;
                }
            }
            return next;
        };

        while (pos < points.size()) {
            ++ans;
            // 从当前位置选一个
            int des = points[pos][1];
            // 找到以这一个为目的，所能消除的最多气球
            // 输入最远目的， 以及开始index, 返回下一个出发点
            pos = walkFaraway(des, pos + 1);
        }
        return ans;
    }

    int findMinArrowShots(vector<vector<int>> &points) {
        assert(points.size() > 0);
        if (points.size() <= 1) {
            return points.size();
        }
        int ans = 0;
        sort(points.begin(), points.end());
        int pos = 0;

        // 关系定义
        // 1、子集
        auto isSubset = [](int l1, int h1, int l2, int h2) {
            return l1 <= l2 && h1 >= h2;
        };
        // 2、crossing
        auto isCrossing = [](int l1, int h1, int l2, int h2) {
            return l2 <= h1 && h1 < h2;
        };
        // 3、不相交
        auto isNonCross = [](int l1, int h1, int l2, int h2) {
            return h1 < l2;
        };

        auto walkFaraway = [&](int start, int des, int next) -> int {
            // 边界
            if (next >= points.size()) {
                return next;
            }
            while (next < points.size()) {
                int nstart = points[next][0];
                int ndes = points[next][1];
                // 不相交
                if (isNonCross(start, des, nstart, ndes)) {
                    break;
                }
                // 子集
                if (isSubset(start, des, nstart, ndes)) {
                    des = ndes;
                    ++next;
                    continue;
                }
                // 交叉
                if (isCrossing(start, des, nstart, ndes)) {
                    ++next;
                    continue;
                }
                assert(false);
            }
            return next;
        };

        while (pos < points.size()) {
            ++ans;
            // 从当前位置pick一个
            int start = points[pos][0];
            int des = points[pos][1];
            // 找到以消除当前气球为目的，顺便能消除的最多气球
            // 输入最远目的， 以及开始index, 返回下一个pick
            pos = walkFaraway(start, des, pos + 1);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[10,16],[2,8],[1,6],[7,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4],[5,6],[7,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5]]\n
// @lcpr case=end

 */
