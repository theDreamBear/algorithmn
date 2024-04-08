/*
 * @lc app=leetcode.cn id=LCR 115 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 115] 序列重建
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
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size() + 1;
        vector<unordered_set<int>> g(n);
        vector<int> ingree(n);
        for (auto& vec : sequences) {
            for (int i = 1; i < vec.size(); i++) {
                int from = vec[i - 1];
                int to = vec[i];
                if (!g[from].count(to)) {
                    g[from].insert(to);
                    ingree[to]++;
                }
            }
        }
        queue<int> q;
        for (int i = 1; i < ingree.size(); i++) {
            if (ingree[i] == 0) {
                q.push(i);
            }
        }
        while (q.size() == 1) {
            auto v = q.front();
            q.pop();
            for (auto& w : g[v]) {
                if (--ingree[w] == 0) {
                    q.push(w);
                }
            }
        }
        return q.empty();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[[1,2],[1,3],[2,3]]\n
// @lcpr case=end

 */

