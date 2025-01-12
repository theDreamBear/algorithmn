/*
 * @lc app=leetcode.cn id=1304 lang=cpp
 * @lcpr version=30204
 *
 * [1304] 和为零的 N 个不同整数
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
    vector<int> sumZero(int n) {
        vector<int> ans; 
        for (int i = 1; i <= n / 2; i++) {
                ans.push_back(i);
                ans.push_back(-i);
            }
        if (n % 2 != 0) {
            ans.push_back(0);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

