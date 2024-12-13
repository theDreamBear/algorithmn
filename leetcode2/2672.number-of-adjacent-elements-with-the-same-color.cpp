/*
 * @lc app=leetcode.cn id=2672 lang=cpp
 * @lcpr version=30204
 *
 * [2672] 有相同颜色的相邻元素数目
 */
#include <bits/stdc++.h>

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
// @lcpr-template-endamespace std;
// @lc code=start
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>> &queries) {
        int q = queries.size(), cnt = 0;
        vector<int> ans(q), a(n + 2); // 避免讨论下标出界的情况
        for (int qi = 0; qi < q; qi++) {
            int i = queries[qi][0] + 1, c = queries[qi][1]; // 下标改成从 1 开始
            if (a[i]) cnt -= (a[i] == a[i - 1]) + (a[i] == a[i + 1]);
            a[i] = c;
            cnt += (a[i] == a[i - 1]) + (a[i] == a[i + 1]);
            ans[qi] = cnt;
        }
        return ans;
    }

    // 写的好复杂啊
    vector<int> colorTheArray1(int n, vector<vector<int>> &queries) {
        vector<int> arr(n);
        map<int, int> idx;
        // left -> right;
        idx[0] = n - 1;
        int res = 0;
        auto split = [&](int l, int v) {
            auto it = idx.lower_bound(l);
            if (it != idx.end() and (*it).first == l) {
                int s = (*it).first, t = (*it).second;
                if (s == l) {
                    int left = l, right = l;
                    it = idx.erase(it);
                    if (s + 1 <= t) {
                        idx[s + 1] = t;
                        if (arr[s + 1] != 0) {
                            res--;
                        }
                    }
                    it = idx.lower_bound(l);
                    // 和和前面的合并
                    auto pre = it;
                    while (pre != idx.begin()) {
                        pre = prev(pre);
                        if (arr[pre->first] == v and pre->second + 1 == left) {
                            res -= (pre->second - pre->first);
                            left = pre->first;
                            pre = idx.erase(pre);
                        } else {
                            break;
                        }
                    }
                    // 和后面的合并
                    auto nxt = it;
                    while (nxt != idx.end()) {
                        if (arr[nxt->first] == v and nxt->first == right + 1) {
                            res -= (nxt->second - nxt->first);
                            right = nxt->second;
                            nxt = idx.erase(nxt);
                        } else {
                            break;
                        }
                    }
                    res += (right - left);
                    idx[left] = right;
                }
            } else if (it != idx.begin()) {
                it = prev(it);
                int s = (*it).first, t = (*it).second;
                it = idx.erase(it);
                // 左右切分
                // [s, l - 1], [l, l], [l + 1, t]
                int left = l, right = l;
                if (l <= t) {
                    if (l - 1 >= s) {
                        idx[s] = l - 1;
                        if (arr[s] != 0) {
                            res--;
                        }
                    }
                    //idx[l] = l;
                    if (l + 1 <= t) {
                        idx[l + 1] = t;
                        if (arr[l + 1] != 0) {
                            res--;
                        }
                    }
                }
                // 和和前面的合并
                it = idx.lower_bound(l);
                auto pre = it;
                while (pre != idx.begin()) {
                    pre = prev(pre);
                    if (arr[pre->first] == v and pre->second + 1 == left) {
                        res -= (pre->second - pre->first);
                        left = pre->first;
                        pre = idx.erase(pre);
                    } else {
                        break;
                    }
                }
                // 和后面的合并
                auto nxt = it;
                while (nxt != idx.end()) {
                    if (arr[nxt->first] == v and nxt->first == right + 1) {
                        res -= (nxt->second - nxt->first);
                        right = nxt->second;
                        nxt = idx.erase(nxt);
                    } else {
                        break;
                    }
                }
                res += (right - left);
                idx[left] = right;
            }
            // 区间合并
        };
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < queries.size(); i++) {
            int j = queries[i][0], v = queries[i][1];
            if (arr[j] != v) {
                arr[j] = v;
                split(queries[i][0], queries[i][1]);
            }
            ans[i] = res;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n[[0,2],[1,2],[3,1],[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[[0,100000]]\n
// @lcpr case=end

 */
