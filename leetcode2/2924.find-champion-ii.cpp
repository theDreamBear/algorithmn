/*
 * @lc app=leetcode.cn id=2924 lang=cpp
 * @lcpr version=30122
 *
 * [2924] 找到冠军 II
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
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for (auto& vec: edges) {
            indegree[vec[1]]++;
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (ans == -1) {
                    ans = i;
                } else {
                    return -1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,1],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0,2],[1,3],[1,2]]\n
// @lcpr case=end

 */

