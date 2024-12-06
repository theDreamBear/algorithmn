/*
 * @lc app=leetcode.cn id=826 lang=cpp
 * @lcpr version=30204
 *
 * [826] 安排工作以达到最大收益
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
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // 偏序问题
        int n = difficulty.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        ranges::sort(idx, [&](int l, int r) {
            return difficulty[l] < difficulty[r];
        });
        ranges::sort(worker);
        int ans = 0;
        int j = 0;
        int pmax = 0;
        for (int i = 0; i < worker.size(); i++) {
            int p = worker[i];
            for (; j < n and difficulty[idx[j]] <= p; j++) {
                pmax = max(pmax, profit[idx[j]]);
            }
            ans += pmax;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,6,8,10]\n[10,20,30,40,50]\n[4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [85,47,57]\n[24,66,99]\n[40,25,25]\n
// @lcpr case=end

 */

