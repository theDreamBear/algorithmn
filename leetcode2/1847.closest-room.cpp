/*
 * @lc app=leetcode.cn id=1847 lang=cpp
 * @lcpr version=30204
 *
 * [1847] 最近的房间
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
const int inf = INT_MAX / 2;
class Solution {
public:
    class Seg {
    public:
        const vector<vector<int>>& arr;
        vector<int> tr;

        Seg(const vector<vector<int>>& arr):arr(arr), tr(arr.size() << 2) {
            build(1, 1, arr.size());
        }

        void maintain(int o) {
            //tr[o] = max(tr[o << 1], tr[o << 1 | 1]);
            if (arr[tr[o << 1]][1] >= arr[tr[o << 1 | 1]][1]) {
                tr[o] = tr[o << 1];
            } else {
                tr[o] = tr[o << 1 | 1];
            }
        }

        // 存最左最大值下标
        void build(int o, int l, int r) {
            if (l == r) {
                tr[o] = l - 1;
                return;
            }
            int m = (l + r) >> 1;
            build(o << 1, l, m);
            build(o << 1 | 1, m + 1, r);
            maintain(o);
        }

        // L, R 当前区间, l, r 查询区间
        int query(int o, int L, int R, int l, int r, int val) {
            if (l <= L and R <= r) {
                return arr[tr[o]][1] >= val ? tr[o] : -1;
            }
            int ans = -1;
            int m = (L + R) >> 1;
            if (m >= l) {
                int res = query(o << 1, L, m, l, r, val);
                if (res > 0) {
                    ans = res;
                }
            }
            if (m < r and ans == -1) {
                int res = query(o << 1 | 1, m + 1, R, l, r, val);
                if (res > 0) {
                    ans = res;
                }
            }
            return ans;
        }

        int binary_right(int left, int right, int val) {
            int low = left, high = right;
            while (low + 1 < high) {
                int mid = (low + high) >> 1;
                if (query(1, 1, arr.size(), mid, right, val) != -1) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            if (query(1, 1, arr.size(), high, right, val) != -1) {
                return high;
            }
            if (query(1, 1, arr.size(), low, right, val) != -1) {
                return low;
            }
            return -1;
        }

        int binary_left(int left, int right, int val) {
            int low = left, high = right;
            while (low + 1 < high) {
                int mid = (low + high) >> 1;
                if (query(1, 1, arr.size(), left, mid, val) != -1) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            if (query(1, 1, arr.size(), left, low, val) != -1) {
                return low;
            }
            if (query(1, 1, arr.size(), left, high, val) != -1) {
                return high;
            }
            return -1;
        }
    };

    vector<int> closestRoom_seg(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        rooms.push_back({0, 0});
        rooms.push_back({INT_MAX, 0});
        // 离散
        ranges::sort(rooms, [&](auto& a, auto& b){
            return a[0] < b[0];
        });
        auto getrank = [&](int pref) {
            return lower_bound(rooms.begin(), rooms.end(), pref, [&](auto& a, int b) {
                return a[0] < b;
            }) - rooms.begin() + 1;
        };
        int n = rooms.size();
        // <= preJ 的最大的

        // >= preJ 的最小的
        Seg seg(rooms);
        int m = queries.size();
        vector<int> ans(m, -1);
        for (int i = 0; i < queries.size(); i++) {
            int prej = queries[i][0], sz = queries[i][1];
            int rk = getrank(prej);
            int left = 1, right = rk;
            if (rooms[rk - 1][0] > prej) {
                right--;
            }
            auto rv = seg.binary_left(right + 1, n, sz) - 1;
            auto lv = seg.binary_right(1, right, sz) - 1;
            if (lv == -2 and rv == -2) {
                continue;
            }
            if (lv == -2) {
                ans[i] = rooms[rv][0];
            } else if (rv == -2) {
                ans[i] = rooms[lv][0];
            } else if (prej - rooms[lv][0] <= rooms[rv][0] - prej) {
                ans[i] = rooms[lv][0];
            } else {
                ans[i] = rooms[rv][0];
            }
        }
        return ans;
    }

    // 离线 + 偏序
    // 保证查询的时候, 可选的都是可用的
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        ranges::sort(rooms, {}, [](auto& a) {
            return -a[1];
        });
        int m = queries.size(), n = rooms.size();
        vector<int> ans(m);
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        ranges::sort(idx, {}, [&](auto& i) {
            return -queries[i][1];
        });
        int j = 0;
        set<int> ss;
        for (int i = 0; i < m; i++) {
            int prej = queries[idx[i]][0], sz = queries[idx[i]][1];
            while (j < n and rooms[j][1] >= sz) {
                ss.insert(rooms[j][0]);
                j++;
            }
            int res = -1;
            auto it = ss.upper_bound(prej);
            if (it != ss.begin()) {
                res = *prev(it);
            }
            if (it != ss.end()) {
                if (res == -1 or *it - prej < prej - res) {
                    res = *it;
                }
            }
            ans[idx[i]] = res;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,2],[1,2],[3,2]]\n[[3,1],[3,3],[5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[2,3],[3,5],[4,1],[5,2]]\n[[2,3],[2,4],[2,5]]\n
// @lcpr case=end

 */

