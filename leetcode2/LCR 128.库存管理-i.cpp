/*
 * @lc app=leetcode.cn id=LCR 128 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 128] 库存管理 I
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
    int stockManagement1(vector<int>& stock) {
        return *min_element(stock.begin(), stock.end());
    }

    int stockManagement(vector<int>& stock) {
        if (stock.size() == 1) {
            return stock.front();
        }
        int low = 0, high = stock.size() - 1;
        while (low + 1 < high) {
            int mid = (high - low) / 2 + low;
            if (stock[mid] > stock[high]) {
                low = mid;
            } else if (stock[mid] < stock[high]) {
                high = mid;
            } else {
                // 这个得特殊处理
                high--;
            }
        }
        return min(stock[low], stock[high]);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,8,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,7,9,1,2]\n
// @lcpr case=end

 */

