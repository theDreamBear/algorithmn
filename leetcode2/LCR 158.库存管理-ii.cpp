/*
 * @lc app=leetcode.cn id=LCR 158 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 158] 库存管理 II
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
    int inventoryManagement(vector<int>& stock) {
        int ct = 0;
        int value = -1;
        for (int i = 0; i < stock.size(); i++) {
            if (ct == 0) {
                value = stock[i];
                ct++;
                continue;
            }
            ct = (value == stock[i]) ? ct + 1: ct - 1;
        }
        return value;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6, 1, 3, 1, 1, 1]\n
// @lcpr case=end

 */

