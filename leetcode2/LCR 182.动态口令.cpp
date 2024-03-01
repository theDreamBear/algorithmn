/*
 * @lc app=leetcode.cn id=LCR 182 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 182] 动态口令
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
    void flip(string& str, int low, int high) {
        for (int i = low, j = high; i < j; i++, j--) {
            swap(str[i], str[j]);
        }
    }

    string dynamicPassword(string password, int target) {
        flip(password, 0, target - 1);
        flip(password, target, password.size() - 1);
        flip(password, 0, password.size() - 1);
        return password;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "s3cur1tyC0d3"\n4\n
// @lcpr case=end

// @lcpr case=start
// "lrloseumgh"\n6\n
// @lcpr case=end

 */

