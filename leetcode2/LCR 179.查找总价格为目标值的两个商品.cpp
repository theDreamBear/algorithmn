/*
 * @lc app=leetcode.cn id=LCR 179 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 179] 查找总价格为目标值的两个商品
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
    vector<int> twoSum1(vector<int>& price, int target) {
        unordered_map<int, int> exist;
        for (int i = 0; i < price.size(); i++) {
            exist[price[i]] = i;
        }
        for (int i = 0; i < price.size(); i++) {
            if (exist.count(target - price[i]) and exist[target - price[i]] > i) {
                return {price[i], target - price[i]};
            }
        }
        return {0, 0};
    }

    vector<int> twoSum2(vector<int>& price, int target) {
        for (int i = 0; i < price.size(); i++) {
            auto pos = lower_bound(price.begin() + i + 1, price.end(), target - price[i]);
            if (pos == price.end()) {
                continue;
            }
            int p = pos - price.begin();
            if (price[p] == target - price[i]) {
                return {price[i], price[p]};
            }
        }
        return {0, 0};
    }

    vector<int> twoSum(vector<int>& price, int target) {
        int i = 0, j = price.size() - 1;
        while (i < j) {
            while (i < j and price[i] + price[j] > target) {
                --j;
            }
            if (i >= j) {
                break;
            }
            if (price[i] + price[j] == target) {
                return {price[i], price[j]};
            }
            ++i;
        }
        return {0, 0};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3, 9, 12, 15]\n18\n
// @lcpr case=end

// @lcpr case=start
// [8, 21, 27, 34, 52, 66]\n61\n
// @lcpr case=end

 */

