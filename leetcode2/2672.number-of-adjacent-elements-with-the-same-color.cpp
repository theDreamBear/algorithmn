/*
 * @lc app=leetcode.cn id=2672 lang=cpp
 * @lcpr version=30204
 *
 * [2672] 有相同颜色的相邻元素数目
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>   arr(n);
        map<int, int> idx;
        // left -> right;
        idx[0]     = n - 1;
        auto split = [&](int l, int v) {
            auto it = idx.lower_bound(l);
            if (it != idx.end() and (*it).first == l) {
                int s = (*it).first, t = (*it).second;
                if (s == l) {
                    idx[s] = s;
                    if (s + 1 <= t) {
                        idx[s + 1] = t;
                    }
                }
            } else if (it != idx.begin())
            return 0;
        };
        return {};
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
