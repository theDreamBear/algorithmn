/*
 * @lc app=leetcode.cn id=面试题 01.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 01.02] 判定是否互为字符重排
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
    bool CheckPermutation(string s1, string s2) {
        ranges::sort(s1);
        ranges::sort(s2);
        return s1 == s2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n"bca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"bad"\n
// @lcpr case=end

 */

