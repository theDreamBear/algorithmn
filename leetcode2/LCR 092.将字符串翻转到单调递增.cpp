/*
 * @lc app=leetcode.cn id=LCR 092 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 092] 将字符串翻转到单调递增
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
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i < n + 1; i++) {
            prefix[i] = prefix[i - 1] + (s[i - 1] == '0' ? 0 : 1);
        }
        // 全0 全1 的最小值
        int ans = min(prefix[n], n - prefix[n]);
        for (int i = 0; i < n; i++) {
            // 枚举i为0 且i为边界
            int zero = prefix[i + 1] +  (n - 1 - i - (prefix[n] - prefix[i + 1]));
            ans = min(ans, zero);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "00110"\n
// @lcpr case=end

// @lcpr case=start
// "010110"\n
// @lcpr case=end

// @lcpr case=start
// "00011000"\n
// @lcpr case=end

 */

