/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 * @lcpr version=30204
 *
 * [1833] 雪糕的最大数量
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
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = 1e5 + 1;
        vector<int> cnt(mx);
        for (auto v: costs) cnt[v]++;
        int ans = 0;
        for (int i = 1; i < mx; i++) {
            if (i <= coins) {
                if (cnt[i] == 0) {
                    continue;
                }
                int canBuy = min(cnt[i], coins / i);
                ans += canBuy;
                coins -= i * canBuy;
            } else {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,4,1]\n7\n
// @lcpr case=end

// @lcpr case=start
// [10,6,8,7,7,8]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,6,3,1,2,5]\n20\n
// @lcpr case=end

 */

