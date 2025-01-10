/*
 * @lc app=leetcode.cn id=860 lang=cpp
 * @lcpr version=30204
 *
 * [860] 柠檬水找零
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
    bool lemonadeChange(vector<int>& bills) {
        int cnt[30]{};
        for (auto v: bills) {
            cnt[v]++;
            if (v != 5) {
                // 找零
                int repay = v - 5;
                if (v == 20) {
                    if (cnt[10] >= 1 and cnt[5] >= 1) {
                        cnt[10]--;
                        cnt[5]--;
                    } else if (cnt[5] >= 3) {
                        cnt[5] -= 3;
                    } else {
                        return false;
                    }
                }
                if (v == 10) {
                    if (cnt[5] >= 1) {
                        cnt[5]--;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,5,5,10,20]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,10,10,20]\n
// @lcpr case=end

 */

