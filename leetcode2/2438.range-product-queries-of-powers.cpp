/*
 * @lc app=leetcode.cn id=2438 lang=cpp
 * @lcpr version=30204
 *
 * [2438] 二的幂数组中查询范围内的乘积
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
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> arr;
        int base = 0;
        while (n) {
            int v = (1 << base);
            if ((n & v) == v) {
                arr.push_back(base);
                n -= v;
            }
            base++;
        }
        vector<int> pre(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++) {
            pre[i + 1] = pre[i] + arr[i];
        }
        int mod = 1e9 + 7;
        int m = queries.size();
        vector<int> ans(m);
        auto quick = [&](int m) {
            int base = 2;
            int ans = 1;
            while (m) {
                if (m & 1) ans = (long long)ans * base % mod;
                base = (long long)base * base % mod;
                m >>= 1;
            }
            return ans;
        };
        for (int i = 0; i < m; i++) {
            int left = queries[i][0], right = queries[i][1];
            ans[i] = quick(pre[right + 1] - pre[left]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 15\n[[0,1],[2,2],[0,3]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,0]]\n
// @lcpr case=end

 */

