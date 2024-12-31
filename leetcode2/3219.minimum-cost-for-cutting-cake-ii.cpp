/*
 * @lc app=leetcode.cn id=3219 lang=cpp
 * @lcpr version=30204
 *
 * [3219] 切蛋糕的最小总开销 II
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
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        ranges::sort(horizontalCut, greater<>{});
        ranges::sort(verticalCut, greater<>{});
        long long ans = 0;
        long long hcnt = 1, vcnt = 1;
        for (int i = 0, j = 0; i + 1 < m or j + 1 < n; ) {
            int hv = i + 1 < m ? horizontalCut[i]: 0;
            int vv = j + 1 < n ? verticalCut[j]: 0;
            //if (hv >= vv) {
                if (hv >= vv) {
                    ans += vcnt * hv;
                    hcnt++;
                    i++;
                } else {
                    ans += hcnt * vv;
                    vcnt++;
                    j++;
                }
           // }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n[1,3]\n[5]\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n[7]\n[4]\n
// @lcpr case=end

 */

