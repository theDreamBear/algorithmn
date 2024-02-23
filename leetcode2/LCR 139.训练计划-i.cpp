/*
 * @lc app=leetcode.cn id=LCR 139 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 139] 训练计划 I
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
    vector<int> trainingPlan1(vector<int>& actions) {
        partition(actions.begin(), actions.end(), [](int v) {
            return v % 2 == 1;
        });
        return actions;
    }

    vector<int> trainingPlan(vector<int>& actions) {
        /*
            [0, low] 为奇数区间
            (low, i) 偶数区间
            [i, end) 待处理区间
        */
        int low = -1;
        for (int i = 0; i < actions.size(); i++) {
            if (actions[i] & 0x1) {
                ++low;
                swap(actions[low], actions[i]);
            }
        }
        return actions;
    }

    vector<int> trainingPlan2(vector<int>& actions) {
        int low = 0, high = actions.size() - 1;
        while (low < high) {
            while (low < high and (actions[low] & 0x1)) {
                ++low;
            }
            while (low < high and (actions[high] & 0x1) == 0) {
                --high;
            }
            if (low < high) {
                swap(actions[low], actions[high]);
            }
        }
        return actions;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

