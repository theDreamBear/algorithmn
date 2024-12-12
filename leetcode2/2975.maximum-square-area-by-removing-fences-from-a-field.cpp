/*
 * @lc app=leetcode.cn id=2975 lang=cpp
 * @lcpr version=30204
 *
 * [2975] 移除栅栏得到的正方形田地的最大面积
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
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto f = [&](vector<int>& a, int mx) {
            a.push_back(1);
            a.push_back(mx);
            ranges::sort(a);
            unordered_set<int> set;
            for (int i = 0; i < a.size(); i++) {
                for (int j = i + 1; j < a.size(); j++) {
                    set.insert(a[j] - a[i]);
                }
            }
            return set;
        };
        auto hs = f(hFences, m);
        auto hv = f(vFences, n);
        if (hs.size() > hv.size()) swap(hs, hv);
        int ans = 0;
        for (auto x: hs) {
            if (hv.contains(x)) {
                ans = max(ans, x);
            }
        }
        return ans ? (long long) ans * ans % (int)(1e9 + 7) : -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n3\n[2,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 6\n7\n[2]\n[4]\n
// @lcpr case=end

 */

