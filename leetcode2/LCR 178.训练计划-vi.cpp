/*
 * @lc app=leetcode.cn id=LCR 178 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 178] 训练计划 VI
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
    int trainingPlan1(vector<int>& actions) {
        unordered_map<int, int> ct;
        for (auto v : actions) {
            ct[v]++;
        }
        for (auto& kv : ct) {
            if (kv.second == 1) {
                return kv.first;
            }
        }
        return 0;
    }
    
    int trainingPlan(vector<int>& actions) {
        int l = 0, r = 0;
        for (auto v : actions) {
            int t = l;
            l = (~l & r & v) | (l & ~r & ~v);
            r = ~t & (r ^ v);
        }
        return r;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5, 7, 5, 5]\n
// @lcpr case=end

// @lcpr case=start
// [12, 1, 6, 12, 6, 12, 6]\n
// @lcpr case=end

 */

