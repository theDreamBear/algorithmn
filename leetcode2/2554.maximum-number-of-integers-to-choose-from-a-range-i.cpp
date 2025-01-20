/*
 * @lc app=leetcode.cn id=2554 lang=cpp
 * @lcpr version=30204
 *
 * [2554] 从一个范围内选择最多整数 I
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
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban(banned.begin(), banned.end());
        int ans = 0;
        for (int i = 1; i <= n and maxSum >= i; i++) {
            if (ban.contains((i))) {
                continue;
            }
            ans++;
            maxSum -= i;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,6,5]\n5\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n8\n1\n
// @lcpr case=end

// @lcpr case=start
// [11]\n7\n50\n
// @lcpr case=end

 */

