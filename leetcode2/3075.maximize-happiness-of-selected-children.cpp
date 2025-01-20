/*
 * @lc app=leetcode.cn id=3075 lang=cpp
 * @lcpr version=30204
 *
 * [3075] 幸福值最大化的选择方案
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
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        ranges::sort(happiness, greater<>{});
        for (int i = 0; i < k; i++) {
            ans += max(0, happiness[i] - i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,5]\n1\n
// @lcpr case=end

 */

